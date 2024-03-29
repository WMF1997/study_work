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
            if (c == '\n')
            {
                LineCount++;
            }
        }
        Results.push_back(LineCount);
    }
    return Results;
}

int CountLines(const std::string& FileName)
{
    std::ifstream In(FileName);
    return std::count( 
        std::istreambuf_iterator<char>(In), 
        std::istreambuf_iterator<char>(), 
        '\n');
}

std::vector<int> CountLinesInFiles_FP_1(const std::vector<std::string>& Files)
{
    std::vector<int> Results;

    for (const auto& File : Files)
    {
        Results.push_back(CountLines(File));
    }

    return Results;
}

std::vector<int> CountLinesInFiles_FP_2(const std::vector<std::string>& Files)
{
    std::vector<int> Results(Files.size());
    std::transform(Files.cbegin(), Files.cend(), 
        Results.begin(), 
        CountLines);
    return Results;
}

// std::vector<int> CountLinesInFiles_FP_3(const std::vector<std::string>& Files)
// {
//     return Files | std::transform(CountLines);
// }

int main(void)
{
    std::vector<std::string> Files = {"CountLinesInFiles.cpp"};
    std::vector<int> Result = CountLinesInFiles(Files);
    for (auto& OneResult : Result)
    {
        cout << OneResult << endl;
    }
    return 0;
}
