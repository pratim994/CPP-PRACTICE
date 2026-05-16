#include <iostream>
#include <vector>
#include <thread>
#include <queue>
#include <functional>
#include <mutex>
#include <condition_variable>
#include <future>
#include <atomic>

#include <chrono>

class ThreadPool {
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;

    std::mutex queue_mutex;
    std::condition_variable condition;
    std::atomic<bool> stop;

public:
    ThreadPool(size_t threads = std::thread::hardware_concurrency())
        : stop(false)
    {
        for (size_t i = 0; i < threads; ++i) {
            workers.emplace_back([this]() {
                while (true) {
                    std::function<void()> task;

                    {
                        std::unique_lock<std::mutex> lock(this->queue_mutex);

                        this->condition.wait(lock, [this]() {
                            return this->stop || !this->tasks.empty();
                        });

                        if (this->stop && this->tasks.empty())
                            return;

                        task = std::move(this->tasks.front());
                        this->tasks.pop();
                    }

                    task(); // execute outside lock
                }
            });
        }
    }

    // submit task and get future result
    template<class F, class... Args>
    auto submit(F&& f, Args&&... args)
        -> std::future<typename std::invoke_result<F, Args...>::type>
    {
        using return_type = typename std::invoke_result<F, Args...>::type;

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<F>(f), std::forward<Args>(args)...)
        );

        std::future<return_type> res = task->get_future();

        {
            std::lock_guard<std::mutex> lock(queue_mutex);

            if (stop)
                throw std::runtime_error("submit on stopped ThreadPool");

            tasks.emplace([task]() { (*task)(); });
        }

        condition.notify_one();
        return res;
    }

    ~ThreadPool() {
        stop = true;
        condition.notify_all();

        for (std::thread &worker : workers)
            worker.join();
    }
};

int heavy_task(int x)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    return x*x;
}


int main(){
   // ThreadPool pool(std::thread::hardware_concurrency());

   const int N = 20;

   //single thread benchmarking 
   auto start1 = std::chrono::high_resolution_clock::now();

   for(int i = 0; i < N; ++i)
   {
    heavy_task(i);

   }

   auto end1 = std::chrono::high_resolution_clock::now();

   // Threadpool and benchmarking 

   ThreadPool pool(4);

   std::vector<std::future<int>> futures;

   auto start2= std::chrono::high_resolution_clock::now();

   for(int i =0; i < N; ++i){

        futures.push_back(pool.submit(heavy_task, i));
   }

   for(auto &f : futures){
        f.get();
   }

   auto end2 = std::chrono::high_resolution_clock::now();


    std::cout << "Single-thread: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count()
              << " ms\n";

    std::cout << "Thread pool: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(end2 - start2).count()
              << " ms\n";

    
}


/*upgraded threadpool :

    -> use of conditional variables : no cpu waste 
        threads sleep until new work arrives or pool shuts down 
        No busy waiting 


    -> std::future : get return values , propogate exceptions  and behave like std::aync 

    -> std::unique_lock : for lock and unlock flexibility 

    -> FIFO queue : better scheduling 

    #further ideas :
        -> backend job systems 
        -> parallel  algorithms i.e quick sort and bogo sort
        -> high performance pipelines

        #maybe work stealing : each thread has its iwn queue and steals work from others

        lock free data structure 

        -> I used std::thread::hardware_concurrency() to prevent oversubscription


*/
