//
// Created by tooyoung on 2021/1/26.
//

#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector <vector<int>> shiftGrid(vector <vector<int>> &grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        k %= (row * col);
        if (k == 0) {
            return grid;
        }
        vector<vector<int>> res;
        int idx = row * col - k + 1;
        int x = idx / col;
        int y = idx % col;
        int n = row * col;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
            }
        }
        return res;
    }
};
