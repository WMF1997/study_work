#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

int main(void)
{
    std::vector<int> vec;
    cout << vec.size() << endl;
    cout << vec.capacity() << endl; 
    cout << vec.max_size() << endl;
    for (int i=0; i<10000; i++)
    {
        vec.push_back(i);
    }
    cout << vec.size() << endl;
    cout << vec.capacity() << endl; 
    cout << vec.max_size() << endl;

    vec.clear();
    cout << vec.capacity() << endl; 
    cout << vec.max_size() << endl;
    
    vec.push_back(10000);
    vec.push_back(10001);
    vec.push_back(10002);
    vec.push_back(10003);
    vec.push_back(10004);

    cout << vec.size() << endl;
    cout << vec.capacity() << endl; 
    cout << vec.max_size() << endl;

    vec.shrink_to_fit();
    cout << vec.size() << endl;
    cout << vec.capacity() << endl; 
    cout << vec.max_size() << endl;

    
    
    return 0;
}