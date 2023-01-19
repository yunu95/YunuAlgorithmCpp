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
#include <array>
#define FOR(i,j) for(int i = 0;i<j;i++)

using namespace std;

// https://www.algospot.com/judge/problem/read/SNAIL

// N
// A_C_B-1
// A_C_B = A_C_B-1  
std::array<std::array<double, 1001>, 1001> cache{ -1 };
int C;
int M;
int N;

double GetProb(int rainyDays)
{
    double& ret = cache[M][rainyDays];
    if (ret > 0)
    {
        return ret;
    }
    if (rainyDays == M)
    {
        return ret = pow(0.75, M);
    }
    if (rainyDays == 0)
    {
        return ret = pow(0.25, M);
    }
    //return ret = GetProb(rainyDays - 1) * (M - rainyDays + 1) / static_cast<double>(rainyDays) * 3;
    return ret = GetProb(rainyDays + 1) / (M - rainyDays) * static_cast<double>(rainyDays + 1) * 1 / 3.0f;
}

// 이항분포
// 1 2 a b
// 2 1 b a
// 2 2 
// 1 1
// 1 1 2 3C1 a a b 
// 1 2 2

int main()
{
    for (auto& eachArr : cache)
        eachArr.fill(-1);
    cin >> C;
    vector<double> ret;
    FOR(i, C)
    {
        cin >> N;
        cin >> M;
        double sum = 0;
        int leastRainy = N - M;
        if (leastRainy <= 0)
        {
            cout << 1.0f;
        }
        else
        {
            for (int i = leastRainy; i <= M; i++)
            {
                sum += GetProb(i);
            }
            ret.push_back(sum);
            //cout << sum;
        }
    }
    for (auto& each : ret)
        printf("%.9f\n", each);
}
