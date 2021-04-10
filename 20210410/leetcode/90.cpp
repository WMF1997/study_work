#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

class Solution
{
public:
	std::vector<std::vector<int>> subStringWithDup(std::vector<int>& nums)
	{
		std::vector<std::vector<int>> result;
		std::vector<int> item;
		std::set<std::vector<int>> res_set;  // 用来存储相应的结果的. 
		// res_set.insert(item);  // 1  这个地方有点"多此一举"了. 不应该在这里添加空的集合, 而是需要将已有的进行排序才行. (!顺序不一样的, 也都是一个!)
		std::sort(nums.begin(), nums.end());  // 1  我们需要进行排序才行. 
		result.push_back(item);
		generate(0, nums, result, item, res_set);
		return result;
	}
private:
	void generate(
		int i, 
		std::vector<int>& nums, 
		std::vector<std::vector<int>>& result, 
		std::vector<int>& item, 
		std::set<std::vector<int>> &res_set)
	{
		if (i >= nums.size())
		{
			return;
		}
		item.push_back(nums[i]);
		// if ( res_set.find(item)!=res_set.end() )  // 2
		if (res_set.find(item) == res_set.end())  // 2  如果是没有找到相应的数据, 然后, 填入一个新的才行. 
		{
			result.push_back(item);  // 3
			res_set.insert(item);
		}
		generate(i+1, nums, result, item, res_set);
		item.pop_back();
		generate(i+1, nums, result, item, res_set);
	}

};

int main(void)
{
	std::vector<int> nums = {2, 1, 2, 2};
	std::vector<std::vector<int>> result;
	Solution solve;
	result = solve.subStringWithDup(nums);
	for (int i=0; i<result.size(); ++i)
	{
		for (int j=0; j<result[i].size(); ++j)
		{
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}
	return 0;
}