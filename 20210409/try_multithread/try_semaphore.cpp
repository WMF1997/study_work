#include <iostream>
#include <thread>
// #include <semaphore.h>  // do not have semaphore in Visual Studio. 
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

int main(void)
{
	sem_init(&sem_1, 0, 0);
	sem_init(&sem_2, 0, 0);
	std::thread t1(PrintFirst, NULL);
	std::thread t2(PrintSecond, NULL);
	std::thread t3(PrintThird, NULL);
	t1.join();
	t2.join();
	t3.join();
	return 0;
}