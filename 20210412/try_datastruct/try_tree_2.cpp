#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x) : val(x), Left(nullptr), Right(nullptr) {}
};

void BFS_print(TreeNode* root)
{
    std::queue<TreeNode*> Q;
    Q.push(root);  // 1
    while (!Q.empty())  // 2
    {
        TreeNode* node = Q.front();
        Q.pop();  // 3
        printf("[%d]\n", node->val);
        if (node->Left)  // 4
        {
            Q.push(node->Left);
        }
        if (node->Right)
        {
            Q.push(node->Right);
        }
    }
}

int main(void)
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(5);
    TreeNode d(3);
    TreeNode e(4);
    TreeNode f(6);
    a.Left = &b;
    a.Right = &c;
    b.Left = &d;
    b.Right = &e;
    c.Right = &f;
    BFS_print(&a);
    return 0;
}