//
// Created by tooyoung on 2021/2/3.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        // 10以上必定重复
        n = min(10, n);
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i < n; ++i) {
            int cnt = 1;
            // 计算A9 i-1
            int j = i - 2;
            while (j >= 0) {
                cnt *= (9 - j);
                j--;
            }
            dp[i] = dp[i - 1] + 9 * cnt;
        }
        return dp.back();
    }
};