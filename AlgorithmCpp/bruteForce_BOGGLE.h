//https://www.algospot.com/judge/problem/read/BOGGLE
#pragma once
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

char board[5][5];
bool isProspective[5][5][100] = { true };
vector<string> words;
const int deltaRow[] = { 1,1,0,-1,-1,-1,0,1 };
const int deltaCol[] = { 0,1,1,1,0,-1,-1,-1 };
const auto testInput = "1\nURLPM\nXPRET\nGIAET\nXTNZY\nXOQRS\n6\nPRETTY\nGIRL\nREPEAT\nKARA\nPANDORA\nGIAZAPX";

bool BackTracking(int row, int col, string word) {
    if (row < 0 || row>5 || col < 0 || col >5)
        return false;
    if (word.length() == 1 && word[0] == board[row][col])
        return true;
    if (word[0] != board[row][col])
        return false;
    FOR(direction, 8)
        if (BackTracking(row + deltaRow[direction], col + deltaCol[direction], word.substr(1)))
            return true;
    return false;
}
void BOGGLE() {
#ifdef test
    stringstream cin(testInput);
#endif
    int C = 1;
    cin >> C;
    FOR(i, C) {
        int n;
        vector<bool> found;
        FOR(j, 25) {
            char letter;
            cin >> letter;
            board[j / 5][j % 5] = letter;
        }
        cin >> n;
        words = vector<string>(n);
        found = vector<bool>(n);
        FOR(j, n) {
            cin >> words[j];
        }
        FOR(j, 25) {
            auto row = j / 5;
            auto col = j % 5;
            // BackTracking
            FOR(k, n) {
                /*if (failedBefore[i][j][k])
                    continue;*/
                if (BackTracking(row, col, words[k]))
                    found[k] = true;
            }
        }
        FOR(j, n)
            cout << words[j] << ' ' << (found[j] ? "YES" : "NO") << '\n';
    }
}


#ifndef YunuComputer
int main() {
    BOGGLE();
}
#endif

