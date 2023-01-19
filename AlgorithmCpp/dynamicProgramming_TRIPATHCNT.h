#pragma once
//�� ���¿� ���� �ﰢ�� ������� ��ġ�� �ڿ������� �ֽ��ϴ�.
//�� ���� ���ڿ��� ������, �� ���� �� ĭ�� �Ʒ��� ������ �� �Ʒ� �ٷ� �������� ��θ� ������� �մϴ�.
//��δ� �Ʒ� �ٷ� ������ ������ �ٷ� �Ʒ� ����, Ȥ�� ������ �Ʒ� ���ڷ� ������ �� �ֽ��ϴ�.
//
//�� �� ������ ���� ���� ū ��δ� �ϳ��� �ƴ϶� ���� ���� �� �ֽ��ϴ�.
//���� ��� �� �ﰢ��������{ 9, 7, 2, 6 }��{ 9, 7, 3, 5 }�� ���� ��� �ִ��� 24�̰�, { 9, 7, 3, 5 }�� �� �� �����ϰŵ��.
//
//�ﰢ���� �־��� �� �ִ� ����� ���� ���� ���α׷��� �ۼ��ϼ���.
//
//�Է�
//�Է��� ù �ٿ��� �׽�Ʈ ���̽��� �� C(C <= 50)�� �־����ϴ�.
//�� �׽�Ʈ ���̽��� ù �ٿ��� �ﰢ���� ũ�� n(2 <= n <= 100)�� �־�����, �� �� n�ٿ��� �� 1��~n���� ���ڷ� �ﰢ�� �� �����ٿ� �ִ� ���ڰ� ���ʺ��� �־����ϴ�.
//�� ���ڴ� 1 �̻� 100000 ������ �ڿ����Դϴ�.
//
//���
//�� �׽�Ʈ ���̽����� �� �ٿ� �ִ� ����� ���� ����մϴ�.
//
//����� ���� 230 ���϶�� �����ص� �����ϴ�.
//
//https://www.algospot.com/judge/problem/read/TRIPATHCNT
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

namespace TRIPATHCNT {
    int costMatrix[100][100];
    //int sumMatrix[100][100];
    int prospectMatrix[100][100];
    int max;
    int n;
    vector<vector<int>> pathCache;

    int MaxPaths(int row = 0, int col = 0)
    {
        if (row == n - 1)
            return 1;

        int ret = 0;
        if (prospectMatrix[row + 1][col] >= prospectMatrix[row + 1][col + 1])
            ret += MaxPaths(row + 1, col);

        if (prospectMatrix[row + 1][col] <= prospectMatrix[row + 1][col + 1])
            ret += MaxPaths(row + 1, col + 1);

        return ret;
    }
    void TRIPATHCNT();
    void TRIPATHCNT()
    {
#ifdef test
        stringstream cin(string("2 4 1  1 1  1 1 1  1 1 1 1  4 9 5 7 1 3 2 3 5 5 6"));
#endif
        int C;
        cin >> C;
        FOR(i, C)
        {
            cin >> n;
            pathCache = vector<vector<int>>(n, vector<int>());
            for (int j = 0; j < n; j++)
                pathCache[j] = vector<int>(j + 1, -1);

            for (int j = 0; j < n; j++)
                for (int k = 0; k <= j; k++)
                {
                    cin >> costMatrix[j][k];
                    prospectMatrix[j][k] = costMatrix[j][k];
                }

            for (int j = n - 2; j >= 0; j--)
                for (int k = 0; k <= j; k++)
                {
                    prospectMatrix[j][k] += prospectMatrix[j + 1][k] > prospectMatrix[j + 1][k + 1] ? prospectMatrix[j + 1][k] : prospectMatrix[j + 1][k + 1];
                }
            cout << MaxPaths(0, 0) << endl;
        }
    }
}
#ifndef YunuComputer
int main()
{
    TRIPATHCNT::TRIPATHCNT();
}
#endif

