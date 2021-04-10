#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
	std::vector<std::vector<int>> subsets(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> result;
		std::vector<int> item;
		result.push_back(item);
		generate(0, nums, item, result);
		return result;
	}
private:
	void generate(int i, std::vector<int>& nums, std::vector<int>& item, std::vector<std::vector<int>>& result)
	{
		if (i > nums.size())  // 1
		{
			return;
		}
		item.push_back(nums[i]);  // 2  // 需要注意的是, 放入的是存在的数组nums的第i个, 而不是i! 
		result.push_back(item);
		generate(i+1, nums, item, result);
		result.pop_back();  // 3
		generate(i+1, nums, item, result);

	}
};