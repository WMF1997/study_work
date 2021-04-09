#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool canJump(std::vector<int>& nums)
    {
        std::vector<int> index;
        for (int i=0; i<nums.size(); i++)
        {
            // index[i] = i + nums[i];  // 1
            index.push_back(i + nums[i]);  // 1  //   初始化相应"能跳跃多远"的数组. 
        }
        int jump = 0;
        int max_index = index[0];  // 从头开始初始化. 
        // while()  // 2
        while ( jump < index.size() && jump <= max_index )  // 2  // 直到jump跳到了数组的尾部, 或者jump超越了当前可以跳跃的最远的位置. 
        {
            if (max_index < index[jump])
            {
                max_index = index[jump]; // 3  // 如果当前可以跳跃更远, 那么更新max_index. 
            }
            // 4
            jump++; // 4
        }
        // if ()  // 5
        if (jump == index.size())  // 5  // 如果jump能够抵达数组的尾部. 
        {
            return true;
        }
        return false;
    }
};

int main(void)
{
    std::vector<int> nums = {2, 3, 1, 1, 4};
    Solution Solve;
    cout << std::boolalpha << Solve.canJump(nums) << endl;
    return 0;
}