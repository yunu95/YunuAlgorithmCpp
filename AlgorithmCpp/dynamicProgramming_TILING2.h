#pragma once
//2xn 크기의 사각형을 2x1 크기의 사각형으로 빈틈없이 채우는 경우의 수를 구하는 프로그램을 작성하세요.
//
//예를 들어 n=5라고 하면 다음 그림과 같이 여덟 가지의 방법이 있습니다.
//
//경우의 수는 n이 커지면 아주 커질 수 있으므로, 1000000007으로 나눈 값을 대신 출력하세요.
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수(C <= 50)가 주어집니다. 그후 C줄에 각각 1개의 자연수로 n(1 <= n <= 100)이 주어집니다.
//
//출력
//각 테스트 케이스마다 한 줄에 경우의 수를 1000000007로 나눈 나머지를 출력합니다. 
//https://algospot.com/judge/problem/read/TILING2

//#define test
//#define JM
#define FOR(i,n) for(int i=0;i<n;i++)

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

#ifndef JM
namespace TILING2 {
    int moduloOperand = 1000000007;
    int C;
    int N;

    vector<int> cache;
    int GetMax(const int index)
    {
        if (index >= N)
            return 0;
        if (index == N - 1)
            return 1;
        if (index == N - 2)
            return 2;

        int& ret = cache[index];
        if (ret != -1)
            return ret;

        ret = (GetMax(index + 1) + GetMax(index + 2)) % moduloOperand;

        return ret;
    }
    void TILING2()
    {
#ifdef test
        stringstream cin;
        cin << "3 1 5 100";
#endif
        cin >> C;
        FOR(i, C)
        {
            cin >> N;
            cache = vector<int>(N, -1);
            cout << GetMax(0)<<endl;
        }
    }
}
#else
namespace TILING2
{
}

#endif

#ifndef YunuComputer
int main()
{
    TILING2::TILING2();
}
#endif

