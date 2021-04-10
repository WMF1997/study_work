#include <iostream>
#include <thread>
#include <semaphore.h>  // do not have semaphore in Visual Studio. 
#include <mutex>
using namespace std;

// 首先定义一些全局变量再说. 

sem_t sem_1, sem_2;

void PrintFirst(void)
{
	cout << "First" << endl;
	sem_post(&sem_1);
}

void PrintSecond(void)
{
	sem_wait(&sem_1);
	cout << "Second" << endl;
	sem_post(&sem_2);
}

void PrintThird(void)
{
	sem_wait(&sem_2);
	cout << "Third" << endl;
}
// 信号量的设计... 还真的是一个很大的问题呢. 
// 目前暂时没有更好的想法. 
int main(void)
{
	sem_init(&sem_1, 0, 0);
	sem_init(&sem_2, 0, 0);
	std::thread t1(PrintFirst);
	std::thread t2(PrintSecond);
	std::thread t3(PrintThird);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}