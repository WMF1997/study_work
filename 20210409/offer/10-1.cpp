#include <iostream>
using namespace std;

class Solution
{
public:
	int fib(int n)
	{
		if (n==0 || n==1)
		{
			return 1;
		}
		else
		{
			return n * fib(n-1);
		}
	}
};

int main(void)
{
	Solution Solve;
	int x = 3;
	int y = Solve.fib(x);
	cout << y << endl;
	return 0;
}