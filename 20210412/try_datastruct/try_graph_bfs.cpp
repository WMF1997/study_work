#include <iostream>
#include <vector>
#include <queue>

struct GraphNode
{
    int label;
    std::vector<GraphNode*> neighbors;
    GraphNode(int x) : label(x) {}
};

// 前面说到了DFS和BFS两者, ...
// DFS的实现, 比较容易想得到的是通过递归来实现. 
// BFS的实现是通过添加一个额外的堆栈来实现. 
void BFS_graph(GraphNode* node, int visit[])
{
    // 在这, 我是在DFS的基础上修改的BFS代码. 所以, ... 
    std::queue<GraphNode*> Q;
    Q.push(node);

    visit[node->label] = 1;

    while (!Q.empty())  // 1
    {
        GraphNode* node = Q.front();
        Q.pop();
        // 原先DFS在外的显示被弄到了里面了. 
        printf("%d ", node->label);

        for (int i=0; i < node->neighbors.size(); i++)
        {
            if (visit[node->neighbors[i]->label] == 0)
            {
                // BFS_graph(node->neighbors[i], visit);
                Q.push(node->neighbors[i]);
                visit[node->neighbors[i]->label] = 1;
            }
        }
    }
}

int main(void)
{
    const int MAX_N = 5;
    GraphNode* Graph[MAX_N];
    for (int i=0; i<MAX_N; ++i)
    {
        Graph[i] = new GraphNode(i);
    }

    Graph[0]->neighbors.push_back(Graph[4]);  // 相对于DFS的例子, 稍微修改了一下 邻接关系声明的先后顺序. 
    Graph[0]->neighbors.push_back(Graph[2]);
    Graph[1]->neighbors.push_back(Graph[0]);
    Graph[1]->neighbors.push_back(Graph[2]);
    Graph[2]->neighbors.push_back(Graph[3]);
    Graph[3]->neighbors.push_back(Graph[4]);
    Graph[4]->neighbors.push_back(Graph[3]);

    int visit[MAX_N] = {0};

    for (int i=0; i<MAX_N; ++i)
    {
        if (visit[i]==0)
        {
            printf("From label [%d] : ", Graph[i]->label);
            BFS_graph(Graph[i], visit);
            printf("\n");
        }
    }

    for (int i=0; i<MAX_N; ++i)
    {
        delete Graph[i];
    }
    return 0;
}