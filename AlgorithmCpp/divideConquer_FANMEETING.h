// https:// www.algospot.com/judge/problem/read/FANMEETING

#define test
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

namespace FANMEETING {
    void FANMEETING();
    vector<int> Trim(const vector<int>& a) {
        vector<int> result(a);
        for (auto itr = result.rbegin(); itr != result.rend(); itr++)
            if (*itr != 0)
            {
                result.erase(itr.base(), result.end());
                break;
            }
        return result;
    }
    vector<int> ShiftLeft(const vector<int>& operand, const int& shiftNum)
    {
        vector<int> res(operand.size() + shiftNum);
        FOR(i, operand.size())
            res[i + shiftNum] = operand[i];
        return res;
    }
    vector<int> Multiply(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result(a.size() + b.size() - 1);
        FOR(i, a.size())
            FOR(j, b.size())
            result[i + j] += a[i] * b[j];
        return Trim(result);
    }
    vector<int> Sum(const vector<int>& a, const vector<int>& b)
    {
        vector<int> result(max<int>(a.size(), b.size()) + 1);
        FOR(i, a.size())
            result[i] += a[i];
        FOR(j, b.size())
            result[j] += b[j];
        return Trim(result);
    }
    vector<int> Resize(const vector<int>& a, int n)
    {
        if (a.size() > n)
            return a;
        vector<int> ret(n);
        FOR(i, a.size())
            ret[i] = a[i];
        return ret;
    }
    vector<int> SubtractBfromA(const vector<int>& a, const vector<int>& b)
    {
        auto Alonger = a.size() > b.size();
        vector<int> result(Alonger ? a.size() : b.size());

        FOR(i, a.size())
            result[i] = a[i];
        FOR(i, b.size())
            result[i] -= b[i];

        return Trim(result);
    }
    vector<int> Karatsuba(const vector<int>& a, const vector<int>& b, const int& notation = -1) {
        if (a.size() == 0)
            return vector<int>();
        //a is always longer than b by this
        if (a.size() < b.size())
            Karatsuba(b, a);
        if (a.size() < 50)
            return Multiply(a, b);
        auto half = a.size() / 2;
        auto a0 = vector<int>(a.begin(), a.begin() + half);
        auto a1 = vector<int>(a.begin() + half, a.end());
        auto b0 = vector<int>(b.begin(), b.begin() + min<int>(b.size(), half));
        auto b1 = vector<int>(b.begin() + min<int>(b.size(), half), b.end());

        auto z0 = Karatsuba(a0, b0);
        auto z2 = Karatsuba(a1, b1);
        auto z1 = Karatsuba(Sum(a1, a0), Sum(b1, b0));
        z1 = SubtractBfromA(z1, z0);
        z1 = SubtractBfromA(z1, z2);

        vector<int> ret(4 * half + 1);
        ret = Sum(ret, ShiftLeft(z0, 0));
        ret = Sum(ret, ShiftLeft(z1, half));
        ret = Sum(ret, ShiftLeft(z2, half + half));
        if (notation > 0)
            FOR(i, ret.size() - 1)
        {
            ret[i + 1] += ret[i] / notation;
            ret[i] %= notation;
        }

        return Trim(ret);
    }
    //#ifndef MainFile
    void FANMEETING() {
#ifdef test
        stringstream cin(string("1\nFFMFMFMFMFMFMFMFMFFFFFFMFFFFMFFFFMFFMFMFMFFMFMFFFMFMFMFMFFMFMFMFFMFMFFMFMFMFFFFFFMFFMFFMFFMFMFMFMFMFMFMFMFMFFMFMFMFMFMFMFMFMFFFMFFMFMMMMFMFMFMFMFFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFMFFFFFMFMFFFFMFFFFMFFFMMMMFFMFMMMFMFMMMFFMFMF\n\
FFFFFFFFFMFFFMFFFMFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFMFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF\n"));
#endif
        int C;
        char members[200000];
        char fans[200000];
        cin >> C;
        FOR(i, C) {
            int fanNum = 0;
            int memberNum = 0;
            int count = 0;
            string members;
            string fans;
            vector<int> fansOperand;
            vector<int> membersOperand;
            char input = 0;
            cin >> members;
            cin >> fans;
            for (auto each : members)
                membersOperand.push_back(each == 'M' ? 1 : 0);
            for (auto each : fans)
                fansOperand.push_back(each == 'M' ? 1 : 0);
            FOR(j, fanNum)
                fansOperand.push_back(fans[j]);
            FOR(j, memberNum)
                membersOperand.push_back(members[memberNum - j - 1]);
            reverse(membersOperand.begin(), membersOperand.end());
            auto res = Karatsuba(membersOperand, fansOperand);
            for (int j = membersOperand.size() - 1; j < fansOperand.size(); j++)
                if (res.size() > j) {
                    if (res[j] == 0)
                        count++;
                }
                else count++;
            cout << count << endl;
        }
    }
    //#endif
}
#ifndef YunuComputer
int main() {
    FANMEETING::FANMEETING();
}
#endif

