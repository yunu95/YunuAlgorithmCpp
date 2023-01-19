// https://www.algospot.com/judge/problem/read/BOARDCOVER
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

using namespace std;

void BOARDCOVER();

#ifndef MainFile
char board[20][20] = { false };
// **  * * 
//  * ** ** 
int dy[12][3] = { {0,0,-1},{0,-1,-1},{0,0,+1} ,{0,+1,+1}, {0,0,+1},{0,-1,-1},{0,0,-1} ,{0,+1,+1} , {0,+1,0},{0,0,-1},{0,-1,0} ,{0,0,+1} };
int dx[12][3] = { {0,+1,+1},{0,0,-1},{0,-1,-1} ,{0,0,+1}, {0,+1,+1},{0,0,+1},{0,-1,-1} ,{0,0,-1} , {0,0,-1},{0,-1,0},{0,0,+1} ,{0,+1,0} };
int H, W;
int solutionCount;

bool Overlay(const int& y, const int& x, const int& layType)
{
    FOR(i, 3) {
        int currentY = y + dy[layType][i];
        int currentX = x + dx[layType][i];
        if (currentX < 0 || currentY < 0 || currentX >= W || currentY >= H)
            return false;
        else
            if (board[currentY][currentX] == '#')
                return false;
    }
    FOR(i, 3)
        board[y + dy[layType][i]][x + dx[layType][i]] = '#';
    return true;
}
void Detach(const int& y, const int& x, const int& layType)
{
    FOR(i, 3)
        board[y + dy[layType][i]][x + dx[layType][i]] = '.';
}
void backTracking(const int& y, const int& x)
{
    if (board[y][x] == '#')
        if (y == H - 1 && x == W - 1)
        {
            solutionCount++;
            return;
        }
        else
            backTracking(x + 1 == W ? y + 1 : y, x + 1 == W ? 0 : x + 1);
    FOR(i, 12)
        if (Overlay(y, x, i))
        {
            if (y == H - 1 && x == W - 1)
                solutionCount++;
            else
                backTracking(x + 1 == W ? y + 1 : y, x + 1 == W ? 0 : x + 1);
            Detach(y, x, i);
        }
}
void BOARDCOVER() {
#ifdef test
    stringstream cin(string("3\n3 7\n#.....# \n#.....# \n##...##\n3 7\n#.....# \n#.....# \n##..### \n8 10\n##########\n#........# \n#........# \n#........# \n#........# \n#........# \n#........# \n########## \n"));
#endif
    int C;
    cin >> C;
    FOR(i, C) {
        cin >> H;
        cin >> W;
        FOR(j, H)
            FOR(k, W)
            cin >> board[j][k];
        solutionCount = 0;
        backTracking(0, 0);
        cout << solutionCount << '\n';
    }
}
#endif

#ifndef YunuComputer
int main() {
    BOARDCOVER();
}
#endif
