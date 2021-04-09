#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

using namespace std;

std::mutex mtx_1;
std::mutex mtx_2;
std::unique_lock<mutex> lock_1(mtx_1, try_to_lock);
std::unique_lock<mutex> lock_2(mtx_2, try_to_lock);

void PrintFirst(void)
{
	cout << "First " << endl;
}

void PrintSecond(void)
{
	cout << "Second " << endl;
}

void PrintThird(void)
{
	cout << "Third " << endl;
}

void first(std::function<void()> printFirst)
{
	printFirst();
	lock_1.unlock();
}

void second(std::function<void()> printSecond)
{
	// lock_guard<mutex> guard(mtx_1);
	unique_lock<mutex> lock(mtx_1);
	printSecond();
	lock_2.unlock();
}

void third(std::function<void()> printThird)
{
	// 这两种书写方式应该都是可以的吧. 
	// lock_guard<mutex> guard(mtx_2);
	unique_lock<mutex> lock(mtx_2);
	printThird();
}


int main(void)
{
	std::thread t1(first, PrintFirst);
	std::thread t2(second, PrintSecond);
	std::thread t3(third, PrintThird);
	t1.join();
	t2.join();
	t3.join();

	return 0;

}
