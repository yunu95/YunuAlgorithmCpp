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
// https://www.algospot.com/judge/problem/read/STRJOIN
int main()
{
    std::multiset<int> strs;

    int c;
    cin >> c;
    for (int i = 0; i < c; i++)
    {
        strs.clear();
        int n;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            int eachStr;
            cin >> eachStr;
            strs.insert(eachStr);
        }
        int cost = 0;
        while (strs.size() != 1)
        {
            int joinedStr = 0;
            joinedStr += *strs.begin();
            strs.erase(strs.begin());
            joinedStr += *strs.begin();
            strs.erase(strs.begin());
            cost += joinedStr;
            strs.insert(joinedStr);
        }
        cout << cost << endl;
    }
}
