#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

std::vector<int> CountLinesInFiles(const std::vector<std::string>& Files)
{
    std::vector<int> Results;
    char c = 0;
    for (const auto& File : Files)
    {
        int LineCount = 0;
        std::ifstream In(File);
        while (In.get(c))
        {
            
        }
    }
}

int main(void)
{
    
}