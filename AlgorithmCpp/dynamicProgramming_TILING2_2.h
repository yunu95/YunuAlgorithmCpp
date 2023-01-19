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

// https://www.algospot.com/judge/problem/read/TILING2

std::array<int, 101> cache{ -1 };
int C;
int N;

int MaxCount(int n)
{
    int& ret = cache[n];
    if (ret != -1)
    {
        return ret;
    }
    return ret = (MaxCount(n - 1) + MaxCount(n - 2)) % 1000000007;

}
int main()
{
    cache.fill(-1);
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cin >> C;
    FOR(i, C)
    {
        cin >> N;
        cout << MaxCount(N) << endl;
    }
}
