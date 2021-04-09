#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution
{
public:
    std::string removeKdigits(std::string num, int k)
    {
        std::vector<int> S;
        std::string result = "";
        for (int i=0; i<num.length(); i++)
        {
            int number = num[i] - '0';
            while (S.size() != 0 && number < S[S.size()-1] && k > 0)  // 1. 
            {
                S.pop_back();
                k--;  // 2  // 因为有k的限制, 所以需要着一个. 
            }
            if ( S.size() !=0 || number != 0 )  // 3. // 这个地方我当时没有想出来. 
            {
                S.push_back(number);
            }
        }
        while (S.size() != 0 && k > 0)
        {
            S.pop_back();  // 4
            k--;
        }
        for (int i=0; i< S.size(); i++)
        {
            result.append(1, S[i]+'0');  // 5  // append是直接在后面需上去的效果. 我想到的是直接相加的效果, 这个并不是很好. 
        }
        if (result == "")
        {
            result = "0";
        }
        return result;
    }
};

int main()
{
    Solution Solve;
    std::string result = Solve.removeKdigits("1432219", 3);
    printf("%s\n", result.c_str());
    std::string result2 = Solve.removeKdigits("100200", 1);
    printf("%s\n", result2.c_str());
    return 0;
}