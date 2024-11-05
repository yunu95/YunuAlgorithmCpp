#pragma once
#define _USE_MATH_DEFINES

#include <deque>
#include <math.h>
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

array<float, 100> circlePosX;
array<float, 100> circlePosY;
array<float, 100> circleRadius;
array<float, 100> circleLeft;
array<float, 100> circlePos;
array<float, 100> circleRight;
// 1�� ���� �������� 0���� �����ֱ� ����.
float deltaAngle{ 0 };

using namespace std;

// �ʼҰ� �����ϴ� ������ ����
float GetHalfAngle(int idx)
{
    return 2 * asinf(circleRadius[idx] / 16.0f);
}

// areCirclesInclusive && isClockWise�� ���� �� ���� �Ÿ��� �� ���� 
// https://www.algospot.com/judge/problem/read/MINASTIRITH
int main()
{
    int C;
    cin >> C;
    for (int i = 0; i < C; i++)
    {
        int N;
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> circlePosX[j];
            cin >> circlePosY[j];
            cin >> circleRadius[j];
            circlePos[j] = atan2f(circlePosX[j], circlePosY[j]);
            if (circlePos[j] < 0)
            {
                circlePos[j] += 2 * M_PI;
            }
            circleLeft[j] = circlePos[j] - GetHalfAngle(j);
            circleRight[j] = circlePos[j] + GetHalfAngle(j);
        }
        // �� ���� ���ư��鼭 
        for (int j = 0; j < N; j++)
        {

        }
    }
}
