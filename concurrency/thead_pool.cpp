#include "STACK.cpp" //using the thread safe stack implementation I did earlier

#include <vector>

#include <thread>

#include <functional>

#include <atomic>

#include<chrono>

#include <iostreams>

#include <memory>

class ThreadPool {

    private:

        std::atomic<bool> done;

        threadsafe_stack<std::function<void()>> work_stack;

        std::vector<std::thread> threads;


        void woker_thread() {

            while(!done){

                std::shared_ptr<std::function<void()>> task = work_stack.try_pop();

                if(task){
                    (*task)();
                }
                else {

                    std::this_thread::yield();
                }

            }
        }

    public:

            ThreadPool() : done(false) {

                unsigned const thread_count = 

                std::thread::hardware_concurrency();

                try {

                    for(unsigned i = 0; i < thread_count; ++i){

                        threads.emplace_back(&ThreadPool::worker_thread, this);
                    }
                }
                catch(...){

                    done = true;

                    throw;
                }
            }
            
            ~ThreadPool() {
                
                done = true;

                for(auto& t : threads){

                    if(t.joinable())

                        t.join();
                }
            }

            template<typename FunctionType>

            void submit(FunctionType f){

                work_stack.push(std::function<void()>(f));
            }
};


int main()
{
    ThreadPool pool;

    for(int i = 0; i < 11; ++i){

        pool.submit([i](){

            std::cout <<  "Task" << i 
            << "running in thread "

            << '\n';

            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }

    std::this_thread::sleep_for(std::chrono::seconds(2));
}

//only a basic implementation 