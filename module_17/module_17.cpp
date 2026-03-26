
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>

#include "utils.h"

int main()
{
	const int N = 100;
	int arr[N];
	random_arr(arr, N);

	long long resSum = 0;
	int resMax = 0, resMin = 0;

	std::jthread tSum([&] {resSum = findSumm(arr, N); });
	std::jthread tMax([&] {resMax = findMax(arr, N); });
	std::jthread tMin([&] {resMin = findMin(arr, N); });

	tSum.join();
	tMax.join();
	tMin.join();

	std::cout << "sum: " << resSum << std::endl;
	std::cout << "max: " << resMax << std::endl;
	std::cout << "min: " << resMin << std::endl;

	std::cout << "<<<<<Second parth>>>>>" << std::endl;

	int arr2[N];

	std::mutex m;
	std::condition_variable cv;
	bool ready = false;

	long long resSum2 = 0;
	int resMax2 = 0, resMin2 = 0;

	auto wait_until_ready = [&] {
		std::unique_lock<std::mutex> lock(m);
		cv.wait(lock, [&] {return ready; }); 
	};

	std::jthread t1([&] {
		wait_until_ready();
		resSum2 = findSumm(arr2, N); });

	std::jthread t2([&] {
		wait_until_ready();
		resMin2 = findMin(arr2, N); });

	std::jthread t3([&] {
		wait_until_ready();
		resMax2 = findMax(arr2, N); });

	random_arr(arr2, N);
	{
		std::lock_guard<std::mutex> lock(m);
		ready = true;
	}

	cv.notify_all();

	t1.join();
	t2.join();
	t3.join();

	std::cout << "sum2: " << resSum2 << std::endl;
	std::cout << "max2: " << resMax2 << std::endl;
	std::cout << "min2: " << resMin2 << std::endl;
	
}
