#include <iostream>
#include <vector>
#include <queue>  // <queue>本质上是一个容器适配器. 另外, 这个是会在BFS中使用. 
using namespace std;

class Solution
{
public:
    int numIslands(std::vector<std::vector<char>>& grid)
    {
        int island_num = 0;
        std::vector<std::vector<int>> mark;
        for (int i=0; i<grid.size(); ++i)
        {
            mark.push_back(std::vector<int>());
            for (int j=0; j<grid[i].size(); ++j)
            {
                mark[i].push_back(0);  // 1
            }
        }
        for (int i=0; i<grid.size(); ++i)
        {
            for (int j=0; j<grid.size(); ++j)
            {
                if ( (grid[i][j] == '1') && (mark[i][j] == 0) )  // 2
                {
                    BFS(mark, grid, i, j);  // 采用DFS或者BFS来完成搜索遍历. 
                    // DFS(mark, grid, i, j);
                    island_num++;  // 3
                }
            }
        }
        return island_num;
    }
private:
    // 从DFS的角度来思考标记的问题. 
    // 为什么说是DFS, 是因为不等当前邻域探索玩, 直接到新的邻域上来进行探索了. 
    void DFS(
        std::vector<std::vector<int>>& mark,
        std::vector<std::vector<char>>& grid, 
        int x, int y    
    )
    {
        mark[x][y] = 1;  // 1  // 标记已经被搜寻到的位置. 
        static const int dx[] = {-1,1,0,0};  // 对应下上左右四个方向的数组. 
        static const int dy[] = {0,0,-1,1};
    
        for (int i=0; i<4; i++)  // 上下左右四个格子要被探索. 
        {
            // 更新x和y, 使用newx和newy来进行更新. 
            int newx = x + dx[i];  // 2
            int newy = y + dy[i];  // 3
            if ( (newx < 0) || (newx >= mark.size()) || (newy < 0) || (newy >= mark.size()) )         
            {
                // return;  // 4
                continue;  // 4 不能是return! 要不然就有的格子就没办法进一步探索了. 这个和之前一直写的递归还是不同的! 
            }
            // if ( mark[x][y] == 0 )  // 5
            if (mark[newx][newy] == 0 && grid[newx][newy] == '1')  // 5  首先, 这个位置肯定是需要判断"邻域"是否满足某条件, 因此在if的条件中不会有x和y, 是newx和newy. 而后, 对没有标记过的, 并且还是"陆地"的位置进行新的邻域探索. 
            {
                DFS(mark, grid, newx, newy);  // 探索新的格子. 
            }
        }
    }
    // 从BFS的角度来思考标记的问题. 
    // 这里需要使用到了队列相关的内容了. 
    void BFS(
        std::vector<std::vector<int>>& mark, 
        std::vector<std::vector<char>>& grid, 
        int x, int y
    )
    {
        static const int dx[] = {-1,1,0,0};  // 对应下上左右四个方向的数组. 
        static const int dy[] = {0,0,-1,1};
        std::queue<std::pair<int, int>> Q;  // 用于宽度优先搜索的队列. 
        Q.push(std::make_pair(x, y));
        mark[x][y] = 1;
        while (!Q.empty())
        {
            x = Q.front().first;
            y = Q.front().second;
            Q.pop();  // 1
            for (int i=0; i<4; ++i)
            {
                int newx = x + dx[i];
                int newy = y + dy[i];
                if ( (newx < 0) || (newx >= mark.size()) || (newy < 0) || (newy >= mark.size()) )
                {
                    continue;
                }
                if ( (mark[newx][newy] == 0) && (grid[newx][newy] == '1') )
                {
                    Q.push(std::make_pair(newx, newy));  // 2
                    // 3
                    mark[newx][newy] = 1;  // 3 得做标记啊! 
                }
            } 
        }
    }
};

int main(void)
{
    std::vector<std::vector<char>> grid;
    char str[10][10] = {"11100", "11000", "00100", "00011"};
    for (int i=0; i<4; i++)
    {
        grid.push_back(std::vector<char>());
        for (int j=0; j<5; j++)
        {
            grid[i].push_back(str[i][j]);
        }
    }
    Solution solve;
    printf("%d\n", solve.numIslands(grid));
    return 0;
}