#pragma GCC optimize("03")

#include <iostream>

#include <chrono>

#include<vector>

using namespace std;

using namespace std::chrono;



int  partition(vector<int>& nums, int low, int high) {
	int pivot = nums[low];
	int i = low;
	int j = high;

	while(i < j) {
		while(nums[i] <= pivot && i <= high - 1){
			i++;
		}
		while(nums[j] > pivot && j >= low+1) {
			j--;
		}
		if(i < j) swap(nums[i], nums[j]);
	}
	swap(nums[low], nums[j]);

	return j;
}

void qs(vector<int>& nums, int low , int high ){
	if(low < high) {
		int pIndex = partition(nums, low, high);
		qs(nums, low, pIndex-1);
		qs(nums, pIndex+1, high);
	}
}


vector<int> quickSort(vector<int>& nums){
	qs(nums, 0, nums.size()-1);
	return nums;
}






int main() {

	ios::sync_with_stdio(false);

	cin.tie(nullptr);

	int n;
	cout << "Enter size of array\n" ;
	cin >> n ;

	vector<int> arr(n);

	for(auto &i : arr) cin >> i;
	
	auto start = high_resolution_clock::now();
	

	 quickSort(arr);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds>(stop-start);

	cout << "sorted array\n";

	for(auto &i :  arr) cout << i << " ";

	cout << "\n";

	cout << "Latency measure:  " << duration.count() << "ms\n";



	return 0;
}

