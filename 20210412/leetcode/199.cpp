#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x) : val(x), Left(nullptr), Right(nullptr) {}
};

class Solution
{
public:
    std::vector<int> rightSideView(TreeNode* root)
    {
        std::vector<int> view;
        std::queue<std::pair<TreeNode*, int>> Q;
        if (root)
        {
            Q.push(std::make_pair(root, 0));
        }
        while (!Q.empty())
        {
            TreeNode* node = Q.front().first;
            int depth = Q.front().second;
            Q.pop();
            // if (!view.at(depth))  // 1
            if (view.size() == depth)  // 1  // 在这里, 根据size来确定是否填入. 例如, 如果想要填入depth=0的情况, 那么, 我们需要结果的vector本身为空, 也就是size为0时. 
            // 同样地, 如果我们想要填入depth=1的那些的话, 我们需要size()为1, 也就是depth=0的全都填好了才行. 
            // size() == depth 是一个小技巧. 用来判断是否填入新的. 还是在原先的列表中继续续下去.. 
            {
                view.push_back(node->val);
            }
            else
            {
                view[depth] = node->val;  // 2
            }
            if (node->Left)  // 3
            {
                Q.push(std::make_pair(node->Left, depth+1));  // 4
            }
            if (node->Right)
            {
                Q.push(std::make_pair(node->Right, depth+1));  // 5
            }
        }
        return view;
    }
};