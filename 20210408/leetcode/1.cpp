#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	std::vector<int> TwoSum(std::vector<int>& nums, int target)
	{
		int n = nums.size();
		std::unordered_map<int, int> hashtable;
		for(int i=0; i<nums.size(); ++i)
		{
			auto it = hashtable.find(target - nums[i]);
			if (it != hashtable.end())
			{
				return {it->second, i};
			}
			hashtable[nums[i]] = i;
		}
		return {};
	}
};

int main(void)
{
	std::vector<int> MyArray = {2, 3, 4, 7, 9};
	Solution S;
	std::vector<int> result;
	result = S.TwoSum(MyArray, 10);
	for (auto& elem : result)
	{
		cout << elem << " ";
	}
	cout << endl;
	return 0;
}