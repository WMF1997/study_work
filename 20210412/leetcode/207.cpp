#include <iostream>
#include <vector>
#include <queue>  // 涉及到图BFS的操作, 大多需要队列这种数据结构. 
using namespace std;

struct GraphNode
{
    int label;
    std::vector<GraphNode*> neighbors;
    GraphNode(int x) : label(x) {}
};

// 这个是采用深度搜索来实现的. 
// class Solution
// {
// public:
//     bool canFinish(
//         int numCourses, 
//         std::vector<std::pair<int, int>>& prerequisites
//     )
//     {
//         std::vector<GraphNode*> graph;
//         std::vector<int> visit;
//         for (int i=0; i<numCourses; i++)
//         {
//             graph.push_back(new GraphNode(i));
//             visit.push_back(-1);
//         }

//         // 按照要求搭建这个图. 
//         for (int i=0; i<prerequisites.size(); i++)
//         {
//             GraphNode* begin = graph[prerequisites[i].second];
//             GraphNode* end = graph[prerequisites[i].first];
//             begin->neighbors.push_back(end);
//         }

//         for (int i=0; i<graph.size(); i++)
//         {
//             if (visit[i] == -1 && !DFS_graph(graph[i], visit))
//             {
//                 return false;
//             }
//         }
//         for (int i=0; i<numCourses; i++)
//         {
//             delete graph[i];
//         }
//         return true;
//     }
// private:
//     bool DFS_graph(GraphNode* node, std::vector<int>& visit)
//     {
//         // 首先是将未在访问的节点, 标注为0
//         node->label = 0;  // 1
//         for (int i=0; i<node->neighbors.size(); i++)
//         {
//             if (node->neighbors[i]->label == -1)  // 2
//             {
//                 if (DFS_graph(node->neighbors[i], visit) == false)  // ==0和==false容易搞混, 因此, 这里还是用false比较好. 
//                 {
//                     return false;  // 3  // 从外部进入这个环路, 最终肯定是不行的. 
//                 }
//             }
//             else if (visit[node->neighbors[i]->label] == 0)
//             {
//                 return false; // 4  // 如果初始的点, 本身就是在这个环中? 也得一样为false. 
//             }
//         }
//         node->label = 1;  // 5  // 所以最后完成之后要将所有的都完成. 
//         return true;
//     }
// };

class Solution
{
public:
	bool canFinish(
		int numCourses, 
		std::vector<std::pair<int, int>>& prerequisities
	)
	{
		std::vector<GraphNode*> graph;
		std::vector<int> degree;

		for (int i=0; i<numCourses; ++i)
		{
			degree.push_back(0);
			graph.push_back(new GraphNode(i));
		}

		for (int i=0; i<prerequisities.size(); ++i)
		{
			GraphNode* begin = graph[prerequisities[i].second];
			GraphNode* end = graph[prerequisities[i].first];
			begin->neighbors.push_back(end);
			degree[prerequisities[i].first]++;  // 通过统计所有边的方法, 实现了计算入度. 通过将first修改为.second, 就是出度. 
		}
		 
		std::queue<GraphNode*> Q;
		for (int i=0; i<numCourses; ++i)
		{
			if (degree[i] == 0)
			{
				Q.push(graph[i]);
			}
		} 

		while (!Q.empty())
		{
			GraphNode* node = Q.front();
			Q.pop();
			for (int i=0; i<node->neighbors.size(); i++)
			{
				degree[node->neighbors[i]->label]--;
				if (degree[node->neighbors[i]->label] == 0)
				{
					Q.push(node->neighbors[i]);
				}
			}
		}

		for (int i=0; i<graph.size(); ++i)
		{
			delete graph[i];
		}

		for (int i=0; i<degree.size(); i++)
		{
			if (degree[i])
			{
				return false;
			}
		}
		return true;
	}
};

int main(void)
{
	std::vector<std::pair<int, int>> prerequisities;
	prerequisities.push_back(std::make_pair(1, 0));
	prerequisities.push_back(std::make_pair(2, 0));
	prerequisities.push_back(std::make_pair(3, 1));
	prerequisities.push_back(std::make_pair(3, 2));
	Solution solve;
	std::cout << std::boolalpha << solve.canFinish(4, prerequisities) << std::endl;
	return 0;
}