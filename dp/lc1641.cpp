//
// Created by tooyoung on 2021/2/2.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(5, 0));
        for (int i = 0; i <= 4; ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j <= 4; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
        int ans = 0;
        for (int i = 0; i <= 4; ++i) {
            ans += dp[n-1][i];
        }
        return ans;

    }
};