#include <stdio.h>
struct TreeNode
{
    int val;
    TreeNode* Left;
    TreeNode* Right;
    TreeNode(int x) : val(x), Left(nullptr), Right(nullptr) {}
};

void PreOrder_Print(TreeNode* Node, int Layer)
{
    if (!Node)
    {
        return;
    }
    for (int i=0; i<Layer-1; ++i)
    {
        printf("     ");
    }
    if (Layer)
    {
        printf("+----");
    }
    printf("[%d]\n", Node->val);
    PreOrder_Print(Node->Left, Layer+1);
    PreOrder_Print(Node->Right, Layer+1);
}

int main(void)
{
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    a.Left = &b;
    a.Right = &c;
    b.Left = &d;
    b.Right = &e;
    c.Right = &f;
    PreOrder_Print(&a, 0);
    return 0;
}