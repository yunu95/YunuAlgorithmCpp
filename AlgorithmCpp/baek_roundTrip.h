#pragma once
//https://www.algospot.com/judge/problem/read/roundTrip
#define FOR(i,n) for(int i=0;i<n;i++)

#include <iostream>
#include <sstream>
#include <algorithm>
//#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

bool biPath[401][401] = { false };
namespace RoundTrip {
    void RoundTrip();

    void RoundTrip() {
#ifdef test
        stringstream cin(string("5 5\n1 3\n3 2\n1 5\n5 4\n4 2"));
#endif 
        int n, p;
        cin >> n;
        cin >> p;
        FOR(i, p)
        {
            int a,b;
            cin >> a;
            cin >> b;
            biPath[a][b] = true;
        }
    }
}
#ifndef YunuComputer
int main() {
    RoundTrip::RoundTrip();
}
#endif
