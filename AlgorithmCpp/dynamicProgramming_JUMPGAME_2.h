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
array<array<int, 100>, 100> board;
array<array<bool, 100>, 100> board_reachable;

void markReachability(int row, int col)
{
    if (row >= 100 || col >= 100)
    {
        return;
    }
    if (board_reachable[row][col])
    {
        return;
    }
    board_reachable[row][col] = true;
    markReachability(row + board[row][col], col);
    markReachability(row, col + board[row][col]);
}
// https://www.algospot.com/judge/problem/read/JUMPGAME
int main()
{
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            board_reachable[j].fill(false);
            for (int k = 0; k < N; k++)
            {
                cin >> board[j][k];
            }
        }
        markReachability(0, 0);
        if (board_reachable[N - 1][N - 1])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}