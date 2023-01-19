#pragma once
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;
// https://www.algospot.com/judge/problem/read/MATCHORDER
int main()
{
    int C;
    int N;
    vector<int> korMMR = vector<int>(100, 0);
    vector<int> rusMMR = vector<int>(100, 0);

    std::cin >> C;

    for (int j = 0; j < C; j++)
    {
        std::cin >> N;
        for (auto i = 0; i < N; i++)
        {
            std::cin >> rusMMR[i];
        }
        for (auto i = 0; i < N; i++)
        {
            std::cin >> korMMR[i];
        }
        std::sort(korMMR.begin(), korMMR.begin() + N, std::less<int>());
        std::sort(rusMMR.begin(), rusMMR.begin() + N, std::less<int>());
        int maxWin = N;
        int rusIdx = 0;
        int korIdx = 0;
        while (korIdx < N)
        {
            if (rusMMR[rusIdx] > korMMR[korIdx])
            {
                maxWin--;
            }
            else
            {
                rusIdx++;
            }
            korIdx++;
        }
        std::cout << maxWin << std::endl;
    }
}
