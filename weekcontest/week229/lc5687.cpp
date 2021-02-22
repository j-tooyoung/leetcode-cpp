//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int ans = INT_MIN;
    int dfs(vector<int> &nums, vector<int> &multipliers, int pos, int left, int right) {
        if (pos == multipliers.size()) {
            return 0;
        }
        int leftRes = dfs(nums, multipliers, pos + 1, left + 1, right) + nums[left] * multipliers[pos];
        int rightRes = dfs(nums, multipliers, pos + 1, left, right - 1) + nums[right] * multipliers[pos];
        return max(leftRes, rightRes);
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        return dfs(nums, multipliers, 0, 0, n - 1);
    }
};