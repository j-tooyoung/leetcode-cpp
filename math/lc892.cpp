//
// Created by tooyoung on 2021/2/12.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] ==0) continue;

                ans += grid[i][j] * 6 - 2 * (grid[i][j] - 1);
                if (j + 1 < n) {
                    ans -= min(grid[i][j + 1], grid[i][j]) * 2;
                }
                if (i + 1 < m) {
                    ans -= min(grid[i + 1][j], grid[i][j]) * 2;
                }
            }
        }
        return ans;
    }
};