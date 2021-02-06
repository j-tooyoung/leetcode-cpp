//
// Created by tooyoung on 2021/2/3.
//
// 动态规划 回溯
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int cnt = 0;
    int ans = INT_MAX;
    void dfs(int n, int m) {
        if (m < 1) return;
        if (n == 1 && m == 1) {
            return;
        }
        if (n < m) {
            dfs(m, n);
        }
        for (int i = 1; i <= m; ++i) {
            ans = min(ans, cnt);
        }
    }

    int tilingRectangle(int n, int m) {
        dfs(n, m);
        return cnt;
    }
};