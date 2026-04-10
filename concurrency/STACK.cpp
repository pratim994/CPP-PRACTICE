//implementation of a thread safe stack which is a wrapper around std::stack<>

#include<memory> // for shared pointer

#include <stack>

#include <mutex>

#include <exception>


struct empty_stack : std::exception {


    const char* what() const throw()
    {
        return "empty stack";
    }

};

template<typename T>

class threadsafe_stack 
{
    private:

        std::stack<T> data;

        mutable std::mutex m;

    public:

        threadsafe_stack() {}

        threadsafe_stack(const threadsafe_stack& other){
            
            std::lock_guard<std::mutex> lock(other.m); // copy constructor performed in the constructor body

            data = other.data;

        }

        threadsafe_stack &operator = (const threadsafe_stack& ) = delete;

        void push(T&& new_value) {

            std::lock_guard<std::mutex> lock(m);

            data.push(std::move(new_value));

        }

        std::shared_ptr<T> pop(){

            std::lock_guard<std::mutex> lock(m);

            if(data.empty()) throw empty_stack(); //checking if stack is empty before popping

            std::shared_ptr<T> const res(std::make_shared<T> (data.top()));

            data.pop();

            return res;

        }

        // a non throwing pop method as exception throwing is computationally expensive in real time production environment
        std::shared_ptr<T> try_pop(){

            std::lock_guard<std::mutex> lock(m);

            if(data.empty()) return std::shared_ptr<T>();

            std::shared_ptr<T> res = std::make_shared<T>(data.top());

            data.pop();

            return res;
        }

        void pop(T& value){

            std::lock_guard<std::mutex> lock(m);

            if(data.empty()) throw empty_stack;

            value = data.top();

            data.pop();

        }

        bool empty() const
        {
            std::lock_guard<std::mutex> lock(m);

            return data.empty();
        }

        size_t size() const {

            std::lock_guard<std::mutex> lock(m);

            return data.size();
        }

    };











