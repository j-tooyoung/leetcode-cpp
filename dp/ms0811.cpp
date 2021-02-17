//
// Created by tooyoung on 2021/2/12.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:

    int waysToChange(int n) {
        int mod = 1e9 + 7;
        int ans = 0;
        vector<int> dp(n + 1, 0);
        dp[0]=1;
        vector<int> coins{1, 5, 10, 25};
        // 遍历顺序很重要
        for (int coin: coins) {
            for (int i = 1; i <= n; ++i) {
                if (i - coin >= 0) {
                    dp[i] = (dp[i] + dp[i - coin]) % mod;
                }
            }
        }
        return dp.back();
    }

    int res = 0;
    int mod = 1e9 + 7;
// error 错误题解
    int waysToChange1(int n) {
        dfs(n);
        return res;
    }

    void dfs(int n) {
        if (n < 0) {
            return;
        }
        if (n == 0) {
            res++;
            res %= mod;
        }
        dfs(n - 1);
        dfs(n - 5);
        dfs(n - 10);
        dfs(n - 25);
    }
};