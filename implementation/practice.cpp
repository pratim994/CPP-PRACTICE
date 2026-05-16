#include <iostream>


short countBits(unsigned int x){

	short num_bits = 0;

	while(x){
		num_bits += x&1;
		x >>=1;
	}

	return num_bits;
}


//parity checks : to check if a binary number has even no of 1s or not ? 0 : 1;


long SwapBits(long x, int i, int j){

	if(((x >> i)&1) != ((x>>j)&1))
	{
		unsigned long bit_mask = (1L << i) | (1L << j);

		x ^= bit_mask;
	}
	return x;
}



typedef enum {WHITE, BLUE, RED} color;

void dutchhflag(int pivot, vector<color>* A_ptr )
{

	vector<color>& A = *A_ptr;
	color pivot = A[pivot_index];

	int smaller = 0, equal = 0, larger = A.size();

	while(equal < larger){
		if(A[equal] < pivot){
			swap(A[smaller++], A[equal++]);
		}
		else if (A[equal] == pivot){
			++equal;
		} else {
			swap(A[equal], A[--larger]);
		}
	}
}

class Semaphore{

	public:
	       	Semaphore(int max_available) : max_available_(max_available), taken_(0) {}

		void acquire() {
			unique_lock<mutex> lock(mx_);
			while(taken_  == max_available_){
				cond_.wait(lock)
			}
			++taken_;
		}

		void release() {
			lock_guard<mutex> lock(mx_);
			--taken_;
			cond_.notify_all();
		}

	private:

		int max_available_;
		int taken_;
		mutex mx_;
		condition_variable cond_;
};


//concurrent tcp ip acces port 
//


void ThreadFun(QueueType& q){
	while(true){
		unique_ptr<tcp::socket> sock;
		q >> sock;
		ProcessReq(sock);
	}
}

const unsigned short kServerPort = 8080;
const int kNThreads = 2;

int main(int argc , char* argv[])
{
	QueueType q(KNThreads);
	for(int i = 0; i < KNThreads; ++i){
		thread(ThreadFunc, ref(req)).detach();

	}
	asio::io_service io_service;
	tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), kServerPort));
	while(true){
		unique_ptr<tcp::socket> sock(new tcp::socket(io_service));
		acceptor.accept(*sock);
		q<< move(sock);
	}
	return 0;
}

