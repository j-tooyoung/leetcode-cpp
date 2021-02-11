//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));

        long mod = 1e9 + 7;
        long ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (arr[i - 1] & 1) {
                dp[i][1] = dp[i - 1][0] + 1;
                dp[i][0] = dp[i - 1][1] ;
            } else {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1];
            }
            ans += dp[i][1];
        }
        return ans % mod;
    }
};