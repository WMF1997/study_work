// 按序打印的非官方解法. 
// 三个线程, 
// [1,2,3] -> PrintFirst, PrintSecond, PrintThird
// [2,3,1] -> PrintSecond, PrintThird, PrintFirst
// 以此类推. 

#include <thread>
#include <iostream>

#include <mutex>  // 我们需要的是互斥量来完成操作. 
#include <functional>  // 应该是底下function<void>的操作吧. 
using namespace std;

// 互斥锁是用来防止多个线程同时访问共享资源对象的机制. 
// 在同一时间只有一个线程可以拥有一个特定的锁对象. 
// 其他线程如果尝试获取锁会阻塞, 直到锁资源被释放, 或是直接返回失败. 

// 总感觉做成LeetCode这样的形式来书写多线程类, 总觉得, 或多或少差一点? 

// 还是重新定义全局变量来思考问题. 
std::mutex mtx_1, mtx_2;

void PrintFirst(void)
{
    // cout << "This is First speaking: id: " << std::this_thread::get_id() << endl;
    // cout << "First: " << std::this_thread::get_id() << endl;
    cout << "First ";
    mtx_1.unlock();
}
void PrintSecond(void)
{
    // cout << "This is Second speaking: id: " << std::this_thread::get_id() << endl;
    mtx_1.lock();
    // cout << "Second: " << std::this_thread::get_id() << endl;
    cout << "Second ";
    mtx_1.unlock();
    mtx_2.unlock();
}
void PrintThird(void)
{
    // cout << "This is Third speaking: id: " << std::this_thread::get_id() << endl;
    mtx_2.lock();
    cout << "Third ";
    // cout << "Third: " << std::this_thread::get_id() << endl;
    mtx_2.unlock();
}

int main(void)
{
    mtx_1.lock();
    mtx_2.lock();

    std::thread t1(PrintThird);
    std::thread t2(PrintFirst);
    std::thread t3(PrintSecond);

    t1.join();
    t2.join();
    t3.join();

    printf("\n");

    return 0;
}


// 封装成为一个类之后, 还是很糊涂... 暂时废弃在下面吧. 
// class Foo
// {
// private:
//     std::mutex mtx1, mtx2;  // 我们首先定义两个互斥量来完成操作. 
// public:
//     Foo (void)
//     {
//         mtx1.lock();
//         mtx2.lock();  // 很直观的想法就是在创建这个对象的时候, 初始化就是加锁的状态. 
//     }
//     void first(std::function<void()> printFirst)
//     {
//         printFirst();
//         mtx1.unlock();
//     }
//     void second(std::function<void()> printSecond)
//     {
//         mtx1.lock();
//         printSecond();
//         mtx1.unlock();
//         mtx2.unlock();  // 
//     }
//     void third(std::function<void()> printThird)
//     {
//         mtx2.lock();
//         printThird();
//         mtx2.unlock();
//     }
// };