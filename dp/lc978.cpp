//
// Created by tooyoung on 2021/2/8.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 1));
//
        dp[0][0] = 1;   // 下降
        dp[0][1] = 1;   // 上升
        int ans = 1;
        for (int i = 1; i < n; ++i) {

            if (arr[i] > arr[i - 1]) {
                dp[i][0] = dp[i - 1][1] + 1;
            } else if (arr[i] < arr[i - 1]) {
                dp[i][1] = dp[i - 1][0] + 1;
            }
            ans = max(ans, dp[i][0]);
            ans = max(ans, dp[i][1]);
        }
        return ans;
    }
};