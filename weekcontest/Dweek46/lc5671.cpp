//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};

    // 多源bfs
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> ans(row, vector<int>(col, -1));
        queue<pair<int, int>> queue;
        // set<pair<int, int>> set;
        vector<vector<bool>> vis(row, vector<bool>(col, false));


        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (isWater[i][j] == 1) {
                    ans[i][j] = 0;
                    queue.emplace(i, j);
                    // set.insert(make_pair(i, j));
                    vis[i][j]=true;
                }
            }
        }
        while (!queue.empty()) {
            auto[x, y] =queue.front();
            queue.pop();
            // cout << x << " " << y<<endl;
            for (int i = 0; i < 4; ++i) {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX < 0 || newX >= row || newY >= col || newY < 0 || isWater[newX][newY] ==1 || vis[newX][newY]) {
                    continue;
                }
                ans[newX][newY] = ans[x][y] + 1;
                queue.emplace(newX, newY);
                vis[newX][newY]=true;
            }
        }
        return ans;
    }
};