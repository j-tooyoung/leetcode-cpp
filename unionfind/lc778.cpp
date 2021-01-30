//
// Created by tooyoung on 2021/1/30.
//

#include "bits/stdc++.h"
using namespace std;

// 并查集 二分 优先队列 Kruskal
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int lo = 0, hi = row * row+1;
        int dirX[] = {-1, 0, 0, 1};
        int dirY[] = {0, -1, 1, 0};
        while (lo < hi) {
            int mid = lo + hi >> 1;

            bool flag = false;
            if (mid >= grid[0][0]) {
                queue<pair<int,int>> q;
                q.emplace(0, 0);
                vector<int> vis(row * row, 0);
                vis[0] = 1;
                while (!q.empty()) {
                    auto[x, y] =q.front();
                    q.pop();
                    if (x == row - 1 && y == row - 1) {
                        flag = true;
                        break;
                    }
                    for (int i = 0; i < 4; ++i) {
                        int newX = x + dirX[i];
                        int newY = y + dirY[i];
                        if (newX < 0 || newY < 0 || newX >= row || newY >= row || vis[newX * row + newY] || grid[newX][newY] > mid) {
                            continue;
                        }
                        vis[newX * row + newY] = 1;
                        q.emplace(newX, newY);
                    }
                }
            }

            if (flag) {
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return lo;
    }
};