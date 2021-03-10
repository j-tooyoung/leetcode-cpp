//
// Created by tooyoung on 2021/3/4.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    const int dr[4] = {1, 1, -1, -1};
    const int dc[4] = {1, -1, -1, 1};

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<vector<int>> ans;
        queue<pair<int,int>> q;
        q.emplace(r0, c0);
        vector<vector<bool>> vis(R, vector<bool>(C, false));
        vis[r0][c0] = true;
        while (!q.empty()) {
            auto[x, y] = q.front();
//            ans.emplace_back(x, y);
            ans.push_back({x, y});
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = x + dr[i];
                int newY = y + dc[i];
                if (newX < 0 || newX >= R || newY < 0 || newY >= C || vis[newX][newY]) {
                    continue;
                }
                q.emplace(newX, newY);
                vis[newX][newY] = true;
            }
        }
        return ans;
    }
};