//
// Created by tooyoung on 2021/2/2.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        // 边界条件
        vector<vector<int>> dp(n + 1, vector<int>(2,-1*0x3f3f3f3f));

        for (int i = 0; i < n; ++i) {
            dp[i + 1][0] = dp[i][0] > 0 ? dp[i][0] + arr[i] : arr[i];
            dp[i + 1][1] = max(dp[i][1] + arr[i], dp[i][0]);
        }
        return max(dp[n][0], dp[n][1]);
    }
};