//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = i; k < j; ++k) {
                    if (k > 0 && k < n - 1) {
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + nums[k] * nums[k - 1] + nums[k + 1]);
                    }else{
                        dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] +
                                                 (k == 0 ? 1 : nums[k - 1]) * nums[k] * (k == n - 1 ? 1 : nums[k + 1]));
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};