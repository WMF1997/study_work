#include <iostream>
#include <atomic>
#include <thread>
#include <functional>
#include <chrono>
using namespace std;

std::atomic<bool> a = false;
std::atomic<bool> b = false;

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

void first(function<void()> printFirst)
{
	printFirst();
	a = true;
}

void second(function<void()> printSecond)
{
	while(!a)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	printSecond();
	b = true;
}

void third(function<void()> printThird)
{
	while (!b)
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	printThird();
}

int main(void)
{
	thread t1(first, PrintFirst);
	thread t2(second, PrintSecond);
	thread t3(third, PrintThird);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}