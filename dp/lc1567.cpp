//
// Created by tooyoung on 2021/2/11.
//


#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] > 0) {
                dp[i][0] = dp[i - 1][0] + 1;
                dp[i][1] = dp[i - 1][1] + 1;
            } else if (nums[i - 1] < 0) {
                dp[i][0] = dp[i - 1][1] + 1;
                dp[i][1] = dp[i - 1][0] + 1;
            } else {
                dp[i][0] = dp[i][1] = 0;
            }
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
    int getMaxLen1(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int neg = 0;
        int pos = 0;
        int lastNeg = -1;
        bool flag = false;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                neg = pos = 0;
                flag = false;
            } else if (nums[i] > 0) {
                pos++;
            }else{
                neg++;
                if (!flag) {
                    lastNeg = i;
                    flag = !flag;
                }
            }
            if (neg % 2 == 0) {
                ans = max(ans, pos + neg);
            }else{
                if (flag) {
                    ans = max(ans,  i - lastNeg);
                }
            }
        }
        return ans;
    }
};