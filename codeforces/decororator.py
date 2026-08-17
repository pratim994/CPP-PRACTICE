from functools import wraps
import time
import asyncio 
import tracemalloc 


tracemalloc.start()

def time_logger(func):
    @wraps(func)
    async def wrapper(*args, **kwargs):

        start = time.perf_counter_ns()

        result = await func(*args, **kwargs)

        elapsed = time.perf_counter_ns() - start

        print(f"{func.__name__}took{elapsed: .4f} nano seconds ")
        return result


    return wrapper


@time_logger
async def  multi_t(name):
    print(f"Thread {name}: starting")
    await asyncio.sleep(1)
    print("Thread inished executing")


    return f"Thread {name} finished" 



async def main():

    print("starting a multithreaded asynchronous function to test the logger decorator ...")

    task1 = asyncio.create_task(multi_t, "A")
    task2 = asyncio.create_task(multi_t, "B")
    task3 = asyncio.create_task(multi_t, "c")

    results = await asyncio.gather(task1, task2, task3)


    print("Main event loop finished : {results}")


asyncio.run(main())


