#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x) : val(x), Left(nullptr), Right(nullptr) {}
};

// class Solution
// {
// public:
//     // 还是先看一下稍微并不是很好的, 或者说, 不能就地转换的思路. 
//     void flatten(TreeNode* root)
//     {
//         std::vector<TreeNode*> node_vec;
//         preorder(root, node_vec);
//         for (int i=1; i<node_vec.size(); i++)
//         {
//             node_vec[i-1]->Left = nullptr;  // 1
//             node_vec[i-1]->Right = node_vec[i];  // 2
//         }
//     }
// private:
//     void preorder(TreeNode* node, std::vector<TreeNode*>& node_vec)
//     {
//         if (!node)
//         {
//             return;
//         }
//         node_vec.push_back(node);  // 3
//         preorder(node->Left, node_vec);
//         preorder(node->Right, node_vec);
//     }
// };

class Solution
{
public:
    void flatten(TreeNode* root)
    {
        TreeNode* last = nullptr;
        preorder(root, last);
    }
private:
    void preorder(TreeNode* node, TreeNode*& last)
    {
        if (!node)
        {
            return;
        }
        // if ()  // 1
        if (!node->Left && !node->Right)  // 1, 有点像是分治算法的最后一步, 合并的那个过程. 
        {
            // 2
            last = node;  // 2
            return;
        }
        TreeNode* left = node->Left;  // 备份左右指针的操作.
        TreeNode* right = node->Right;
        TreeNode* left_last = nullptr;
        TreeNode* right_last = nullptr;
        if (left)
        {
            preorder(left, left_last);
            node->Left = NULL;
            node->Right = left;  // 3
            last = left_last;  // 整个树的last, 就变为左子树的last了. 
        }
        if (right)
        {
            preorder(right, right_last);
            if (left_last)  // 如果存在左子树的时候. 
            {
                left_last->Right = right;  // 4
            }
            // 5
            last = right_last; // 5
        }
    }
};