//
// Created by tooyoung on 2021/2/9.
//
// 状态压缩dp
//https://www.acwing.com/solution/content/28877/
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        const int n = jobs.size();
        const int INF = 0x3f3f3f3f;
        vector<vector<int>> dp(k + 1, vector<int>(1 << n, INF));
        vector<int> sum(1 << n, 0);
        for (int i = 0; i < (1 << n); ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    sum[i] += jobs[j];
                }
            }
        }
        dp[0][0] = 0;
        for (int i = 1; i <= k; ++i) {
            for (int j = 0; j < (1 << n); ++j) {
                // 枚举子集
                for (int sub = j; sub > 0; sub = (sub - 1) & j) {
                    dp[i][j] = min(dp[i][j], max(dp[i - 1][j ^ sub], sum[sub]));
                }
            }
        }
        return dp[k][(1 << n) - 1];
    }
};