//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN / 2));

        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max({max(0, dp[i - 1][j - 1]) + nums1[i - 1] * nums2[j - 1], dp[i - 1][j], dp[i][j - 1]});
            }
        }
        return ans;
    }
};