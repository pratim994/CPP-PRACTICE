#include<iostream>
#include <thread>
#include <semaphore>
using namespace std;

binary_semaphore semaphore(1);
void worker(int id){
	semaphore.acquire();
	cout << "Thread" << id << "aquired the semaphore" << '\n';
	
	semaphore.release();
	cout << "Thread" << id << "released the semaphore" << '\n';
}

int main(){

	thread t1(worker,1);
	thread t2(worker, 2);
	t1.join();
	t2.join();

	return 0;



}

