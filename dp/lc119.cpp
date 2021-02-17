//
// Created by tooyoung on 2021/2/12.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1 , vector<int>(rowIndex+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = dp[i - 1][j] + (j ? dp[i - 1][j - 1] : 0);
            }
        }
        return dp.back();
    }
};