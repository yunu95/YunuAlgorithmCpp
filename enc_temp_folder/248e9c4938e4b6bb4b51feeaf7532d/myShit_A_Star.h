#pragma once

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
#define test

using namespace std;


namespace A_STAR {
    class Node
    {
    public:
        int row = 0, col = 0;
        int g_score = 0;
        char symbol = 'w';
        Node* previousNode = nullptr;
        static Node* dst;
        Node() { }
        Node(int row, int col, int g_score, int row_prev = -1, int col_prev = -1)
            : row(row), col(col), g_score(g_score)
        { }
        int heuristic() const { return abs(row - dst->row) + abs(col - dst->col); }
        int getFScore() const { return g_score + heuristic(); }
    };
    constexpr int dx[4] = { 0,0,1,-1 };
    constexpr int dy[4] = { -1,1,0,0 };
    Node* Node::dst = nullptr;
    bool operator<(const Node& lhs, const Node& rhs)
    {
        return lhs.getFScore() < rhs.getFScore();
    }
    struct NodeCompare
    {
        bool operator()(const Node* lhs, const Node* rhs)const {
            return lhs->getFScore() > rhs->getFScore();
        }
    };

    char map[100][100];
    Node nodeMap[100][100];
    void A_STAR()
    {
#ifdef test
        stringstream cin(string("\
s  we \n\
w  w  \n\
   w  \n\
 wwww \n\
      \n\
  w  w\n\
"));
#endif
        string line;
        Node* start;
        int row = 0;
        while (getline(cin, line))
        {
            FOR(col, line.size())
            {
                if (line[col] == 's')
                    start = &nodeMap[row][col];

                if (line[col] == 'e')
                    Node::dst = &nodeMap[row][col];

                nodeMap[row][col].symbol = line[col];
                nodeMap[row][col].row = row;
                nodeMap[row][col].col = col;
            }
            row++;
        }

        priority_queue<Node*> openSet;
        unordered_set<Node*> closedSet;

        stack<Node*> path;
        openSet.push(start);
        while (!openSet.empty())
        {
            auto currentNode = openSet.top();
            openSet.pop();

            if (closedSet.find(currentNode) != closedSet.end())
                continue;

            if (currentNode == Node::dst)
            {
                auto pathNode = Node::dst;
                while (pathNode != start)
                {
                    path.push(pathNode);
                    pathNode = pathNode->previousNode;
                }
                break;
            }

            closedSet.insert(currentNode);



            for (int i = 0; i < 4; i++)
            {
                auto row = currentNode->row + dy[i];
                auto col = currentNode->col + dx[i];
                if (row < 0 || col < 0)
                    continue;

                if (nodeMap[row][col].symbol == 'w')
                    continue;

                if (closedSet.find(&nodeMap[row][col]) != closedSet.end())
                    continue;
                nodeMap[row][col].g_score = currentNode->g_score + 1;
                nodeMap[row][col].previousNode = currentNode;
                openSet.push(&nodeMap[row][col]);
            }

        }
        while (!path.empty())
        {
            cout << path.top()->row << ',' << path.top()->col << endl;
        }

    }
}
