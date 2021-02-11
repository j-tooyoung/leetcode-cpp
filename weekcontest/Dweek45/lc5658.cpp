//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1, 0);
        int minVal = 0, maxVal = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
            // cout <<pre[i + 1] << " " << minVal << " " << maxVal << endl;
            ans = max(ans, abs(pre[i + 1] - minVal));
            ans = max(ans, abs(pre[i + 1] - maxVal));
            minVal = min(minVal, pre[i + 1]);
            maxVal = max(maxVal, pre[i + 1]);
        }
        return ans == INT_MIN ? 0 : ans;

    }
};