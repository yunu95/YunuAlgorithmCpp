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
// https://www.algospot.com/judge/problem/read/LUNCHBOX
struct Dosirak
{
    int m = 0;
    int e = 0;
};
int main()
{
    int T;
    int N;
    //vector<int> M(0, 10000);
    //vector<int> E(0, 10000);
    vector<Dosirak> dosiraks(10000, Dosirak{});
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int mSum = 0;
        int input;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            dosiraks[j].m = input;
        }
        for (int j = 0; j < N; j++)
        {
            cin >> input;
            dosiraks[j].e = input;
        }
        std::sort(dosiraks.begin(), dosiraks.begin()+N, [](const Dosirak& a, const Dosirak& b) {return a.e > b.e; });
        int elapsed = 0;
        int overallTime = 0;
        for (int j = 0; j < N; j++)
        {
            elapsed += dosiraks[j].m;
            int estimation = elapsed + dosiraks[j].e;
            if (overallTime < estimation)
                overallTime = estimation;
        }
        cout << overallTime << endl;
    }
}
