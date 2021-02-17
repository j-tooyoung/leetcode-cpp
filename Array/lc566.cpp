//
// Created by tooyoung on 2021/2/17.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        if (row * col < r * c) {
            return nums;
        }
        vector<vector<int>> ans(r,vector<int>(c,0));
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int pos = (i * col + j);
                int x = pos / c;
                int y = pos % c;
                ans[x][y] = nums[i][j];
            }
        }
        return ans;
    }
};