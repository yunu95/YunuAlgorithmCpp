// https://www.algospot.com/judge/problem/read/FENCE
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

namespace FENCE {
    void FENCE();
    //#ifndef MainFile
    int fences[40000];
    int LargestPiece(const int& startIndex, const int& endIndex)
    {
        if (startIndex == endIndex)
            return fences[startIndex];
        int max;
        auto leftMax = LargestPiece(startIndex, startIndex + (endIndex - startIndex) / 2);
        auto rightMax = LargestPiece(startIndex + (endIndex - startIndex) / 2 + 1, endIndex);
        max = leftMax > rightMax ? leftMax : rightMax;

        int leftEnd = startIndex + (endIndex - startIndex) / 2;
        int rightEnd = startIndex + (endIndex - startIndex) / 2 + 1;

        int combinedMax = -987654321;
        int currentHeight = min(fences[rightEnd], fences[leftEnd]);
        combinedMax = (rightEnd - leftEnd + 1) * currentHeight;
        while (leftEnd != startIndex || rightEnd != endIndex)
        {
            int foundSize;
            bool expandLeft = rightEnd == endIndex;
            if (!expandLeft&& leftEnd!=startIndex)
                expandLeft = fences[leftEnd - 1] > fences[rightEnd+1];

            if (expandLeft)
                currentHeight = min(currentHeight, fences[--leftEnd]);
            else
                currentHeight = min(currentHeight, fences[++rightEnd]);
            foundSize = (rightEnd - leftEnd + 1) * currentHeight;
            if (foundSize > combinedMax)
                combinedMax = foundSize;
        }
        if (combinedMax > max)
            max = combinedMax;

        return max;
    }
    void FENCE() {
#ifdef test
        stringstream cin(string("3\n7\n7 1 5 9 6 7 3\n7\n1 4 4 4 4 1 1\n4\n1 8 2 2\n"));
#endif
        int C;
        cin >> C;
        FOR(i, C) {
            int N;
            cin >> N;
            FOR(j, N)
                cin >> fences[j];
            cout << LargestPiece(0, N - 1) << endl;
        }
    }
    //#endif
}
#ifndef YunuComputer
int main() {
    FENCE::FENCE();
}
#endif

