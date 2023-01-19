#pragma once
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <array>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;
// https://www.algospot.com/judge/problem/read/PACKING

array<int, 100> desperations;
array<int, 100> volumes;
array<string, 100> name;
array<array<int, 100>, 1001> maxDesp;
int capacity;
int N;

int GetMaxDesp(int capacityLeft, int itemIdx)
{
    if (itemIdx == N)
    {
        return 0;
    }
    int& ret = maxDesp[capacityLeft][itemIdx];
    if (ret != -1) return ret;
    // 만약 아이템을 챙기지 않는다면?
    ret = GetMaxDesp(capacityLeft, itemIdx + 1);
    // 만약 아이템을 챙길 수 있다면?
    if (capacityLeft >= volumes[itemIdx])
    {
        ret = std::max(ret, GetMaxDesp(capacityLeft - volumes[itemIdx], itemIdx + 1) + desperations[itemIdx]);
    }
    return ret;
}
int main()
{
    int C;
    cin >> C;

    for (int i = 0; i < C; i++)
    {
        cin >> N;
        cin >> capacity;
        for (int j = 0; j < N; j++)
        {
            cin >> name[j];
            cin >> volumes[j];
            cin >> desperations[j];
        }
        for (auto& each : maxDesp)
        {
            each.fill(-1);
        }
        array<bool, 100> isContaining{ false };
        int despSum = GetMaxDesp(capacity, 0);
        int itemNum = 0;
        for (int j = 0; j < N; j++)
        {
            if (maxDesp[capacity][j] != maxDesp[capacity][j + 1])
            {
                itemNum++;
                isContaining[j] = true;
            }
        }
        cout << despSum << endl;
        cout << itemNum << endl;
        for (int j = 0; j < N; j++)
        {
            if (isContaining[j])
                cout << name[j] << endl;
        }
    }
}
