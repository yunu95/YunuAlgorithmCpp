﻿#pragma once
// 문제
// 깊이가 n 미터인 우물의 맨 밑바닥에 달팽이가 있습니다. 
// 이 달팽이는 우물의 맨 위까지 기어올라가고 싶어하는데, 달팽이의 움직임은 그 날의 날씨에 좌우됩니다. 
// 만약 비가 내리면 달팽이는 하루에 2미터를 기어올라갈 수 있지만, 날이 맑으면 1미터밖에 올라가지 못합니다.
// 
// 여름 장마가 찾아와, 앞으로 m 일간 각 날짜에 비가 올 확률이 정확히 75%일 전망입니다. 
// m 일 안에 달팽이가 우물 끝까지 올라갈 확률을 계산하는 프로그램을 작성하세요.
// 
// 입력
// 입력의 첫 줄에는 테스트 케이스의 수 C(1≤C≤50) 가 주어집니다. 
// 그 후 각 줄에 우물의 깊이 n(1≤n≤1000)과 장마 기간의 길이 m(1≤m≤1000) 이 주어집니다.
// 
// 출력
// 각 테스트 케이스마다 한 줄에 m일 안에 달팽이가 우물을 탈출할 수 있을 확률을 출력합니다. 
// 10−7 이하의 상대/절대 오차가 있는 답은 정답으로 인정됩니다.
// 
// https:// www.algospot.com/judge/problem/read/SNAIL

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
//#define test

using namespace std;

namespace SNAIL {
    void SNAIL()
    {
#ifdef test
        stringstream cin(string("2 4 1  1 1  1 1 1  1 1 1 1  4 9 5 7 1 3 2 3 5 5 6"));
#endif
        int C;
        cin >> C;
        FOR(i, C)
        {
        }
    }
}
#ifndef YunuComputer
int main()
{
    SNAIL::SNAIL();
}
#endif

