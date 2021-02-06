//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int dp[105][105];

    //记忆化搜索超时
    int dfs(string s, int i, int j) {
        if(i <0 || j >= s.size()) return 0;
        if (i == j) {
            return 1;
        } else if (i > j) {
            return 0;
        } else if (i == j - 1) {
            return s[i] == s[j] ? 1 : 2;
        }
        if(dp[i][j]) return dp[i][j];
        int cnt = INT_MAX;
        for (int k = i + 1; k <= j; ++k) {
            int a = dfs(s, i, k - 1);
            if (s[k] == s[i]) {
                cnt = min(cnt,a +dfs(s, k + 1, j));
            } else {
                cnt = min(cnt,a + dfs(s, k, j));
            }
        }
        dp[i][j] =cnt;
        return  dp[i][j];
    }

    int strangePrinter1(string s) {
        int n = s.size();
        memset(dp, n, 0);
        return dfs(s, 0, n - 1);
    }

    // 区间dp
    int strangePrinter(string s) {

    }
};