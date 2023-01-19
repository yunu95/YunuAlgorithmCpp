#pragma once
//https://www.algospot.com/judge/problem/read/TRIPATHCNT
#define FOR(i,n) for(int i=0;i<n;i++)

#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;

namespace TRIPATHCNT {
    int costMatrix[100][100];
    int sumMatrix[100][100];
    int max;
    int n;
    vector<vector<int>> pathCache;

    int MaxPaths(int row = 0, int col = 0, int sum = 0)
    {
        int& ret = pathCache[row][col];
        if (ret != -1)
            return ret;

        if (row == n - 1)
        {
            ret = sum == max ? 1 : 0;
            return ret;
        }
        //ret = MatxPaths(row + 1,col,sum+) + pathCache[row + 1][col + 1];
        return ret;
    }
    void TRIPATHCNT();
    void TRIPATHCNT()
    {
#ifdef test
        stringstream cin(string("2 4 1 1 1  1 1 1  1 1 1 1  4 9 5 7 1 3 2 3 5 5 6"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            cin >> n;
            pathCache = vector<vector<int>>(n, vector<int>());
            for (int j = 0; j < n; j++)
                pathCache[j] = vector<int>(j + 1, -1);

            for (int j = 0; j < n; j++)
                for (int k = 0; k <= j; k++)
                {
                    cin >> costMatrix[j][k];
                    sumMatrix[j][k] = costMatrix[j][k];
                }

            for (int j = 1; j < n; j++)
                for (int k = 0; k <= j; k++)
                {
                    if (k == 0)
                        sumMatrix[j][k] += sumMatrix[j - 1][k];
                    else if (k == j)
                        sumMatrix[j][k] += sumMatrix[j - 1][k - 1];
                    else
                        sumMatrix[j][k] += sumMatrix[j - 1][k] > sumMatrix[j - 1][k - 1] ? sumMatrix[j - 1][k] : sumMatrix[j - 1][k - 1];
                }
            max = -987654321;
            for (int j = 0; j < n; j++)
                if (max < sumMatrix[n - 1][j])
                    max = sumMatrix[n - 1][j];

            cout << max << endl;
        }
    }
}
#ifndef YunuComputer
int main()
{
    TRIPATHCNT::TRIPATHCNT();
}
#endif

