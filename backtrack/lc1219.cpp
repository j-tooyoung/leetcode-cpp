//
// Created by tooyoung on 2021/2/3.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int ans = 0;
    int dirX[4] = {-1, 0, 0, 1};
    int dirY[4] = {0, 1, -1, 0};

    void dfs(vector<vector<int>> &grid, int row, int col, int x, int y, int val,vector<vector<int>> &vis) {
        if (x < 0 || y < 0 || x >= row || y >= col || grid[x][y] ==0) {
            return;
        }
        for (int i = 0; i < 4; ++i) {
            int newX = x + dirX[i];
            int newY = y + dirY[i];
            if (newX < 0 || newY < 0 || newX >= row || newY >= col || vis[newX][newY] || grid[newX][newY] ==0) {
                ans = max(ans, val);
                continue;
            }
            vis[newX][newY] =1;
            dfs(grid, row, col, newX, newY, val + grid[newX][newY], vis);
            vis[newX][newY] = 0;
        }
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j]) {
                    vis[i][j] = 1;
                    dfs(grid, row, col, i, j, grid[i][j], vis);
                    vis[i][j] = 0;
                }
            }
        }
        return ans;
    }
};