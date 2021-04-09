#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::mutex mtx;
std::condition_variable cv;
int k = 0;

void PrintFirst()
{
	cout << "First" << endl;
	k = 1;
	// cv.notify_all();
	cv.notify_one();  // 随机唤醒一个. 
}

void PrintSecond()
{
	std::unique_lock<std::mutex> MyLock(mtx);
	cv.wait(MyLock, [](){return k==1;} );  // 最终的问题, 好像是出在了这里. 
	cout << "Second" << endl;
	k = 2;
	// cv.notify_one();  // cv.notify_all(); 为什么不行? 
	cv.notify_all();
}

void PrintThird()
{
	std::unique_lock<std::mutex> MyLock(mtx);
	cv.wait(MyLock, [](){return k==2;} );
	cout << "Third" << endl;
}

int main(void)
{
	std::thread t1(PrintFirst);
	std::thread t2(PrintSecond);
	std::thread t3(PrintThird);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}