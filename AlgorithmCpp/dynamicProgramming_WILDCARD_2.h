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

using namespace std;
int C;
int N;

int match[101][101]{ -1 };

string wildCard;
string fileName;

bool MatchWildCard(int w, int s)
{
    int& ret = match[w][s];
    if (ret != -1)
        return ret;

    while (s < fileName.size() && w < wildCard.size() && (wildCard[w] == fileName[s] || wildCard[w] == '?'))
    {
        w++;
        s++;
    }
    if (w == wildCard.size())
    {
        return ret = (s == fileName.size());
    }
    if (wildCard[w] == '*')
    {
        for (int i = s; i <= fileName.size(); i++)
        {
            if (MatchWildCard(w + 1, i))
                return ret = 1;
        }
    }
    return ret = 0;
}

// https://www.algospot.com/judge/problem/read/WILDCARD
int main()
{
    cin >> C;
    vector<string> answers;
    for (int i = 0; i < C; i++)
    {
        cin >> wildCard;
        cin >> N;
            answers.clear();
        for (int j = 0; j < N; j++)
        {
            cin >> fileName;
            for (int idx = 0; idx < 101 * 101; idx++)
                match[idx / 101][idx % 101] = -1;
            if (MatchWildCard(0, 0))
                answers.push_back(fileName);
        }

        cout << endl;
        std::sort(answers.begin(),answers.end());
        for (auto& each : answers)
            cout << each << endl;

    }
}
