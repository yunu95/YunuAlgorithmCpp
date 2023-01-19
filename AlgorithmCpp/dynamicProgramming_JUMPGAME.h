//https://www.algospot.com/judge/problem/read/JUMPGAME
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

namespace JUMPGAME {
    int board[100][100];
    bool reachTable[100][100];
    int n = 1;
    bool isReachable(const int& y, const int& x) {
        if (y == 0 && x == 0)
            return true;
        for (int i = y - 1; i >=0 ; i--)
            if (!reachTable[i][x] && ((i - y) == board[i][x] || (y - i) == board[i][x]))
            {
                reachTable[i][x] = true;
                if (isReachable(i, x)) {
#ifdef test
                    cout << "from row " << y << " and col " << x << endl;
#endif
                    return true;
                }
            }
        for (int i = x - 1; i >=0 ; i--)
            if (!reachTable[y][i] && ((i - x) == board[y][i] || (x - i) == board[y][i]))
            {
                reachTable[y][i] = true;
                if (isReachable(y, i)) {
#ifdef test
                    cout << "from row " << y << " and col " << x << endl;
#endif
                    return true;
                }
            }
        return false;
    }
    void JUMPGAME();
    //#ifndef MainFile
    void JUMPGAME() {
#ifdef test
        stringstream cin(string("2\n7\n2 5 1 6 1 4 1\n6 1 1 2 2 9 3\n7 2 3 2 1 3 1\n1 1 3 1 7 1 2\n4 1 2 3 4 1 2\n3 3 1 2 3 4 1\n1 5 2 9 4 7 0\n7\n2 5 1 6 1 4 1\n6 1 1 2 2 9 3\n7 2 3 2 1 3 1\n1 1 3 1 7 1 2\n4 1 2 3 4 1 3\n3 3 1 2 3 4 1\n1 5 2 9 4 7 0\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            cin >> n;
            FOR(j, n)
                FOR(k, n)
            {
                cin >> board[j][k];
                reachTable[j][k] = false;
            }
            reachTable[n - 1][n - 1] = true;
            cout << (isReachable(n - 1, n - 1) ? "YES" : "NO") << endl;

        }
    }
    //#endif
}
#ifndef YunuComputer
int main() {
    JUMPGAME::JUMPGAME();
}
#endif
