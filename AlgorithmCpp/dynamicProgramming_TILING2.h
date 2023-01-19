#pragma once
//https://algospot.com/judge/problem/read/TILING2

//#define test
//#define JM
#define FOR(i,n) for(int i=0;i<n;i++)

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

#ifndef JM
namespace TILING2 {
    int moduloOperand = 1000000007;
    int C;
    int N;

    vector<int> cache;
    int GetMax(const int index)
    {
        if (index >= N)
            return 0;
        if (index == N - 1)
            return 1;
        if (index == N - 2)
            return 2;

        int& ret = cache[index];
        if (ret != -1)
            return ret;

        ret = (GetMax(index + 1) + GetMax(index + 2)) % moduloOperand;

        return ret;
    }
    void TILING2()
    {
#ifdef test
        stringstream cin;
        cin << "3 1 5 100";
#endif
        cin >> C;
        FOR(i, C)
        {
            cin >> N;
            cache = vector<int>(N, -1);
            cout << GetMax(0)<<endl;
        }
    }
}
#else
namespace TILING2
{
}

#endif

#ifndef YunuComputer
int main()
{
    TILING2::TILING2();
}
#endif

