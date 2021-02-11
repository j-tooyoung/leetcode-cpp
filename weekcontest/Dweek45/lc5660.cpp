//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end(), [&](int i, int j) -> {
            if (events[i][1] == events[j][1]) {
                return events[i][0] - events[j][0];
            }
            return events[i][1] == events[j][1];
        });
        int n = events.size();
        int ans = INT_MIN;
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = 0; i < n; ++i) {
            int lowbound = lower_bound(events.begin(), events.begin() + i, events[i][0]) - events.begin();
            if (k >= 1) {
                dp[i][k] = max(dp[i - 1][k - 1] + events[i][2], dp[i - 1][k]);
            }else{
                dp[i][k] = dp[i - 1][k];
            }
            ans = max(ans, dp[i][k]);
        }
        return ans;

    }
};