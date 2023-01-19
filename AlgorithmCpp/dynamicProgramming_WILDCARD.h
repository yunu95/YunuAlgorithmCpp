//https://www.algospot.com/judge/problem/read/WILDCARD
//#define test
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

namespace WILDCARD {
    bool WildCompare(const string& a, const string& b) {
        if (a.size() != b.size())
            return false;
        FOR(i, a.size())
            if (!(a[i] == b[i] || a[i] == '?' || b[i] == '?'))
                return false;
        return true;
    }
    vector<string> FilterByWildcard(const string& wildcard, const vector<string>& files) {
        string prefix, suffix, buffer;
        bool prefixFlag = true;
        vector<string> substrings;
        stringstream wildcardStream(wildcard);
        while (getline(wildcardStream, buffer, '*'))
        {
            if (buffer.empty()) {
                prefixFlag = false;
                continue;
            }
            if (prefixFlag)
            {
                prefixFlag = false;
                prefix = buffer;
            }
            else
                substrings.push_back(buffer);
        }
        if (wildcard[wildcard.size() - 1] != '*')
        {
            suffix = buffer;
            if (!substrings.empty())
                substrings.erase(substrings.begin() + substrings.size() - 1);
        }
        vector<string> res;
        FOR(i, files.size()) {
            if (!WildCompare(prefix, files[i].substr(0, prefix.size())))
                continue;
            if (!WildCompare(suffix, files[i].substr(files[i].size() - suffix.size())))
                continue;
            auto substring = substrings.begin();
            for (int j = 0; j < files[i].size() && substring != substrings.end(); j++)
                if (WildCompare(*substring, files[i].substr(j, substring->size())))
                    substring++;
            if (substring == substrings.end())
                res.push_back(files[i]);
        }
        return res;
    }
    void WILDCARD();
    //#ifndef MainFile
    void WILDCARD() {
#ifdef test
        stringstream cin(string("2\nhe?p\n3\nhelp\nheap\nhelpp\n*p*\n3\nhelp\npapa\nhello\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            string wildcard;
            int N;
            cin >> wildcard;
            cin >> N;
            vector<string> files(N);
            FOR(i, N)
                cin >> files[i];
            auto res = FilterByWildcard(wildcard, files);
            sort(res.begin(), res.end());
            for (auto each : res)
                cout << each << endl;
        }
    }
    //#endif
}
#ifndef YunuComputer
int main() {
    WILDCARD::WILDCARD();
}
#endif

