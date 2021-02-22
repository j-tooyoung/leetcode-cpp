//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minTrioDegree(int n, vector<vector<int>>& edges) {
        vector<vector<bool>> connected(n + 1, vector<bool>(n + 1, 0));
        vector<int> deg(n + 1);
        for (auto &e: edges) {
            connected[e[0]][e[1]] = connected[e[1]][e[0]] = true;
            deg[e[0]]++;
            deg[e[1]]++;
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (!connected[i][j]) {
                    continue;
                }
                for (int k = j + 1; k <= n; ++k) {
                    if (connected[i][k] && connected[j][k]) {
                        ans = min(ans, deg[i] + deg[j] + deg[k] - 6);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};