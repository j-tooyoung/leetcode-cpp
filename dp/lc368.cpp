//
// Created by tooyoung on 2021/2/5.
//
// 最长递乘数子序列
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        int size = nums.size();
        if (nums.size() == 0 || nums.size() == 1) {
            return nums;
        }
        sort(nums.begin(), nums.end());

        vector<int> dp(size+1, 1);
        vector<int> ans;
        // vector初始化使用方法
        vector<int> memo(size+1, 1);
        int maxVal = 0;
        int end = 0;
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        memo[i] = j;
                    }
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            // cout<< maxVal << endl;
            if (dp[i] > maxVal) {
                end = i;
            }
            maxVal = max(maxVal, dp[i]);
        }
        int prev = end;
        while (maxVal--) {
            ans.push_back(nums[prev]);
            prev = memo[prev];
        }
        reverse(ans.begin(),ans.end());

        return ans;

    }
};