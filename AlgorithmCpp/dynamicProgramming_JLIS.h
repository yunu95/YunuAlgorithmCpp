#pragma once
//어떤 수열에서 0개 이상의 숫자를 지운 결과를 원 수열의 부분 수열이라고 부릅니다.
//예를 들어 '4 7 6'은 '4 3 7 6 9'의 부분 수열입니다.
//중복된 숫자가 없고 오름 차순으로 정렬되어 있는 부분 수열들을 가리켜 증가 부분 수열이라고 부르지요.
//예를 들어 '3 6 9'는 앞의 수열의 증가 부분 수열입니다.
//
//두 개의 정수 수열 A 와 B 에서 각각 증가 부분 수열을 얻은 뒤 이들을 크기 순서대로 합친 것을 합친 증가 부분 수열이라고 부르기로 합시다.
//이 중 가장 긴 수열을 합친 JLIS(JLIS, Joined Longest Increasing Subsequence)이라고 부릅시다.
//예를 들어 '1 3 4 7 9' 은 '1 9 4' 와 '3 4 7' 의 JLIS입니다.
//'1 9' 와 '3 4 7' 을 합쳐 '1 3 4 7 9'를 얻을 수 있기 때문이지요.
//
//A 와 B 가 주어질 때, JLIS의 길이를 계산하는 프로그램을 작성하세요.
//
//입력
//입력의 첫 줄에는 테스트 케이스의 수 c ( 1 <= c <= 50 ) 가 주어집니다.
//각 테스트 케이스의 첫 줄에는 A 와 B 의 길이 n 과 m 이 주어집니다 (1 <= n,m <= 100).
//다음 줄에는 n 개의 정수로 A 의 원소들이, 그 다음 줄에는 m 개의 정수로 B 의 원소들이 주어집니다.
//모든 원소들은 32비트 부호 있는 정수에 저장할 수 있습니다.
//
//출력
//각 테스트 케이스마다 한 줄에, JLIS 의 길이를 출력합니다.
//https://algospot.com/judge/problem/read/JLIS


#define test
#define FOR(i,n) for(int i=0;i<n;i++)

#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <string>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <memory>

using namespace std;

namespace JLIS {
    int n;
    vector<int> LIS(const vector<int>& sequence, vector<vector<int>>& results, const int& start = 0)
    {
        if (start == n - 1)
            return results[start] = vector<int>(1, n - 1);

        vector<int> result = vector<int>(start);
        //int current = sequence[start];
        for (int i = start; i < n; i++)
        {
            if (sequence[i] <= sequence[start])
                continue;

            if (result.size() < (results[i].size() == 0 ? LIS(sequence, results, i).size() : results[i].size()) + 1)
                result = results[i] + 1;
        }
        return results[start] = result;
    }
    void JLIS();
    void JLIS()
    {
#ifdef test
        stringstream cin(string("3\n4\n1 2 3 4\n8\n5 4 3 2 1 6 7 8 \n8\n5 6 7 8 1 2 3 4\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C)
        {
            // n<500
            vector<int> sequence;
            vector<int> results;

            cin >> n;
            sequence = vector<int>(n);
            results = vector<int>(n, -1);
        }
    }
}
#ifndef YunuComputer
int main()
{
    JLIS::JLIS();
}
#endif

