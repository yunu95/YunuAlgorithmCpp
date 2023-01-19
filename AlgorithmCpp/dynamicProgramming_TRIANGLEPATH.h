#pragma once
//https://www.algospot.com/judge/problem/read/TRIANGLEPATH
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

namespace TRIANGLEPATH {
    int costMatrix[100][100];
    int sumMatrix[100][100];
    void TRIANGLEPATH();
    void TRIANGLEPATH() {
#ifdef test
        stringstream cin(string("2\n5\n6\n1  2\n3  7  4\n9  4  1  7\n2  7  5  9  4\n5\n1 \n2 4\n8 16 8\n32 64 32 64\n128 256 128 256 128"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            int n;
            cin >> n;
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
            int max = -987654321;
            for (int j = 0; j < n; j++)
                if (max < sumMatrix[n-1][j])
                    max = sumMatrix[n-1][j];
            cout << max<<endl;
        }
    }
}
#ifndef YunuComputer
int main() {
    TRIANGLEPATH::TRIANGLEPATH();
}
#endif

