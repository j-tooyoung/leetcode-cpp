//
// Created by tooyoung on 2021/2/5.
//
// 01背包
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (auto str : strs) {
            int zero = 0;
            int one = 0;
            for (auto c : str) {
                if (c == '0') {
                    zero++;
                }else{
                    one++;
                }
            }
// 逆序遍历，why
            for (int j = m; j >= zero; --j) {
                for (int k = n; k >= one; --k) {
                    dp[j][k] = max(dp[j][k], dp[j - zero][k - one] + 1);
                }
            }
        }
        return dp[m][n];

    }
};