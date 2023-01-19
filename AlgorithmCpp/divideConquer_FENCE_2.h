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
#define FOR(i,n) for(int i=0;i<n;i++)

using namespace std;
int C;
int N;
int fences[20000];

// https://www.algospot.com/judge/problem/read/FENCE
int GetMaxSqure(int s, int e)
{
    if (s > e)
    {
        cout << "what never ever should happen" << endl;
    }
    if (s == e)
        return fences[s];
    int m = (s + e) / 2;
    int leftMax = GetMaxSqure(s, m);
    int rightMax = GetMaxSqure(m + 1, e);

    int maxSum = max(leftMax, rightMax);
    int currHeight = 0;
    int newS = m;
    int newE = m;
    maxSum = currHeight = fences[m];
    while (newS != s && newE != e)
    {
        if (newS != s && fences[newS - 1] > fences[newE + 1])
        {
            newS--;
            currHeight = std::min(currHeight, fences[newS]);
        }
        else
        {
            newE++;
            currHeight = std::min(currHeight, fences[newE]);
        }
        int newSum = (newE - newS + 1) * currHeight;
        maxSum = max(maxSum, newSum);
    }
    return maxSum;

}
int main()
{
    int C;
    cin >> C;
    vector<int> answers;
    FOR(i, C) {
        int N;
        cin >> N;
        FOR(j, N)
            cin >> fences[j];
        answers.push_back(GetMaxSqure(0, N - 1));
    }
    for (auto& each : answers)
        cout << each << endl;
}