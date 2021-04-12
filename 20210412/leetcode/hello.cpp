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
	std::vector<std::vector<int>> PathSum(TreeNode* root, int sum)  // 指定了根节点和需要的总和. 
	{
		std::vector<std::vector<int>> result;  // 最终想要返回的所有可能的路径. 我们使用std::vector<int>来"模拟"一个栈. 
		std::vector<int> path;
		int path_value = 0;
		preorder(root, path_value, sum, path, result);
		return result;
	}
private:
	void preorder(TreeNode* node, int& path_value, int sum, std::vector<int>& path, std::vector<std::vector<int>>& result)
	{
		if (!node)
		{
			return;
		}
		path_value += node->val;  // 遍历一个节点, 就更新相应的路径值. 
		path.push_back(node->val);  // 1
		if (node->Left==nullptr && node->Right==nullptr && path_value == sum)  // 2
		{
			result.push_back(path);
		}
		preorder(node->Left, path_value, sum, path, result);
		preorder(node->Right, path_value, sum, path, result);

		path_value -= node->val;  // 3
		path.pop_back();  // 在"当前节点的左右节点""全都"遍历完成之后, 自然需要将当前节点弹出来. 
	}
};

int main(void)
{
	TreeNode a(5);
	TreeNode b(4);
	return 0;
}