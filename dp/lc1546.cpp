//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // todo
    int maxNonOverlapping(vector<int>& nums, int target) {
        vector<pair<int, int>> list;
        unordered_map<int, int> map;
        int n = nums.size();
        vector<int> dp(n, 0);
        map[nums[0]] = 0;
        map[0] = -1;

        for (int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
            int diff = nums[i] - target;
            dp[i] = dp[i - 1];
            if (map.count(diff)) {
                dp[i] = max(dp[i], dp[map[diff]] + 1);
            }
            map[nums[i]] = i;
        }
        return dp.back();

    }
};