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
// 1빠 원의 시작점을 0으로 맞춰주기 위함.
float deltaAngle{ 0 };

using namespace std;

// 초소가 차지하는 내각의 절반
float GetHalfAngle(int idx)
{
    return 2 * asinf(circleRadius[idx] / 16.0f);
}

// areCirclesInclusive && isClockWise인 원들 중 가장 거리가 먼 원을 
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
        // 각 원을 돌아가면서 
        for (int j = 0; j < N; j++)
        {

        }
    }
}
