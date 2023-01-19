#pragma once
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

namespace LIS {
    int n;
    vector<int> sequence;
    vector<int> results;
    int Count(const int& start = 0) {
        if (start == n - 1)
            return results[start] = 1;

        int result = 1;
        //int current = sequence[start];
        for (int i = start; i < n; i++)
        {
            if (sequence[i] <= sequence[start])
                continue;
            if (result < (results[i] < 0 ? Count(i) : results[i]) + 1)
                result = results[i] + 1;
        }
        return results[start] = result;
    }
    void LIS();
    void LIS() {
#ifdef test
        stringstream cin(string("3\n4\n1 2 3 4\n8\n5 4 3 2 1 6 7 8 \n8\n5 6 7 8 1 2 3 4\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            // n<500

            cin >> n;
            sequence = vector<int>(n);
            results = vector<int>(n, -1);

            FOR(j, n)
                cin >> sequence[j];

            FOR(j, n)
                Count(j);

            int max = -987654321;
            for (auto each : results)
                if (max < each)
                    max = each;

            cout << max << endl;

        }
    }
}
#ifndef YunuComputer
int main() {
    LIS::LIS();
}
#endif

