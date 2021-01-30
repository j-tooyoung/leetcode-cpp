//
// Created by tooyoung on 2021/1/28.
//


#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    int minimumOperations(string leaves) {
        vector<vector<int>> dp(leaves.size(), vector<int>(3, 0));
        int max = 0x3f3f3f;
        dp[0][0] = (leaves[0] != 'r');
        dp[0][1] = max;
        dp[0][2] = max;
        dp[1][2] = max;

        for (int i = 1; i < leaves.size(); ++i) {
            bool isRed = leaves[i] == 'r';
            bool isYellow = leaves[i] == 'y';
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][0]) + isYellow;
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + isRed;
            if (i >= 2) {
                dp[i][2] = min(dp[i - 1][2], dp[i - 1][1]) + isYellow;
            }
        }
        return dp[leaves.size() - 1][2];
    }
};
