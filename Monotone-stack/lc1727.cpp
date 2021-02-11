//
// Created by tooyoung on 2021/2/10.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j]) {
                    matrix[i][j] = matrix[i - 1][j] + 1;
                }
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < m; ++i) {
            sort(rbegin(matrix[i]), rend(matrix[i]));
            for (int j = 0; j < n; ++j) {
                ans = max(ans, matrix[i][j] * (j + 1));
            }
        }
        return ans;
    }
};