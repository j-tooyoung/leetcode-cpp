//
// Created by tooyoung on 2021/3/4.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {
        int n = envelopes.size();
        if(n==0) return 0;
        vector<int> dp(n, 1);
//        sort(begin(envelopes), end(envelopes), [](const vector<int> &v1, const vector<int> &v2) {
//            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
//        });
        sort(begin(envelopes), end(envelopes), [&](auto &v1, auto &v2) {
            return v1[0] < v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });
        int ans = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[j][0] < envelopes[i][0] && envelopes[j][1] < envelopes[i][1]) {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};