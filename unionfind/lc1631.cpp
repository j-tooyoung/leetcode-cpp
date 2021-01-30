//
// Created by tooyoung on 2021/1/29.
//

#include "bits/stdc++.h"
using namespace std;


class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0},
                                       {1,  0},
                                       {0,  1},
                                       {0,  -1}};
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int row = heights.size();
        int col = heights[0].size();
        int lo = 0, hi = 1e6;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            queue<pair<int, int>> q;
            vector<int> seen(row * col);
            seen[0] = 1;
            q.emplace(0, 0);
            bool flag = false;
            while (!q.empty()) {
                auto[x, y] = q.front();
                q.pop();
                if (x == row - 1 && y == col - 1) {
                    flag = true;
                    break;
                }
                for (int i = 0; i < 4; ++i) {
                    int newX = x + dirs[i][0];
                    int newY = y + dirs[i][1];
                    if (newX < 0 || newY < 0 || newX >= row || newY >= col || seen[newX * col + newY] ||
                        abs(heights[newX][newY] - heights[x][y]) > mid) {
                        continue;
                    }
                    seen[newX * col + newY] = 1;
                    q.emplace(newX, newY);
                }
            }
            // cout<<lo << " "<< hi<<" "<< flag<<endl;
            if (flag) {
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};