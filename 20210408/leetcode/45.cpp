#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
	int jump(std::vector<int>& nums)
	{
		if (nums.size() < 2)
		{
			return 0;  // 如果数组的长度<2, 那么就不用跳跃了. 
		}
		int current_max_index = nums[0];  // 当前可以到达的最远位置. 
		int pre_max_max_index = nums[0];  // 遍历各个位置过程中, 可以到达的最远位置. 
		int jump_min = 1;
		for (int i=0; i<nums.size(); i++)
		{
			// if ()  // 1
			if (i > current_max_index)
			{
				jump_min++;
				// 2
				current_max_index = pre_max_max_index;
			}
			if (pre_max_max_index < nums[i] + i)
			{
				pre_max_max_index = nums[i] + i;  // 3. // 更新pre_max_max_index
			}
		}
		return jump_min;
	}
};


int main(void)
{
	std::vector<int> nums = {2, 3, 1, 1, 4};
	Solution Solve;
	cout << Solve.jump(nums) << endl;
	return 0;
}