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

class Solution
{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<TreeNode*> path;  // 声明遍历用的临时栈
        std::vector<TreeNode*> node_p_path;  // 存储p节点路径. 
        std::vector<TreeNode*> node_q_path;  // 存储q节点路径. 
        int finish = 0;  // 记录是否完成. 
        preorder(root, p, path, node_p_path, finish);  // 1
        path.clear();  // 清空path和finish, 计算q节点所对应的路径. 
        finish = 0;
        preorder(root, q, path, node_q_path, finish);
        int path_len = 0;  // 较短路径的长度
        if (node_p_path.size() < node_q_path.size())  // 2
        {
            path_len = node_p_path.size();
        }
        else
        {
            path_len = node_q_path.size();
        }

        TreeNode* result = nullptr;
        for (int i=0; i<path_len; i++)  // 同时遍历p,q两个节点的路径上的节点. 
        {
            if (node_p_path[i] == node_q_path[i])  // 3
            {
                result = node_p_path[i];
            }
        }
        return result;
    }
private:
    void preorder(
        TreeNode* node,
        TreeNode* search, 
        std::vector<TreeNode*>& path, 
        std::vector<TreeNode*>& result, 
        int& finish
    )
    {
        if (!node || (finish==1))  // 1  // 当node为空, 或者是已经找到了search节点, 直接返回, 结束搜索. 
        {
            return;
        }
        path.push_back(node);  // 先序遍历, 将节点压入path栈. 
        if (node == search)  // 当找到search节点之后, 标记finish变量. 
        {
            finish = 1;
            // preorder(node, search, path, result, finish);  // 2
            result = path;  // 2  // 需要注意的是, 最终这个void函数返回的正是result这个引用! 所以, 如果是真的找到的话, 我们完全不用重新弄来一轮return... 而是直接将中间变量path导出到result上. 
        }
        preorder(node->Left, search, path, result, finish);
        preorder(node->Right, search, path, result, finish);
        path.pop_back();  // 3  // 结束遍历node的时候, 将node节点弹出path栈. 
    }
};