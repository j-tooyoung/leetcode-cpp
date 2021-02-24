//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int ans = INT_MIN;
//    static const int t = 2010;
//    vector<vector<int>> dp(2010, vector<int>(2010,-0x3f3f));
    int dp[1010][1010];

    int dfs1(vector<int> &nums, vector<int> &multipliers, int pos, int left, int right) {
        int &x = dp[left][right];
        if (pos == multipliers.size()) {
            return 0;
        }
        if (dp[left][right] !=-1) {
            return dp[left][right];
        }
        int leftRes = dfs1(nums, multipliers, pos + 1, left + 1, right) + nums[left] * multipliers[pos];
        int rightRes =
                dfs1(nums, multipliers, pos + 1, left, right+1) + nums[nums.size() - right] * multipliers[pos];
        x = max(leftRes, rightRes);
        return x;
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        memset(dp, -1, sizeof dp);

        return dfs1(nums, multipliers, 0, 0, 1);
    }

    int maximumScore1(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<int>> cache(m, vector<int>(m, 0x3f3f3f3f));
        function<int(int, int)> dfs = [&](int i, int j) {
            int k = i + j;
            if (k == m) {
                return 0;
            }
            if (cache[i][j] != 0x3f3f3f3f) {
                return cache[i][j];
            }
            return (cache[i][j] = max(nums[i] * multipliers[k] + dfs(i + 1, j),
                                      nums[n - 1 - j] * multipliers[k] + dfs(i, j + 1)));
        };

        return dfs(0, 0);
    }
};