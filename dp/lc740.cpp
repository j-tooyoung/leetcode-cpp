//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
// 打劫
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(10000 + 10, 0);
        int maxVal = 0;
        for (int i = 0; i < n; ++i) {
            cnt[nums[i]]++;
            maxVal = max(maxVal, nums[i]);
        }
        vector<int> dp(maxVal + 1, 0);
        int ans = 0;
        for (int i = 0; i <= maxVal; ++i) {
            dp[i] = cnt[i] * i;
            if (i >= 2) {
                dp[i] = max(dp[i - 1], max(dp[i], dp[i - 2] + i * cnt[i]));
            }
            ans = max(ans, dp[i]);
        }
        return ans;

    }
};