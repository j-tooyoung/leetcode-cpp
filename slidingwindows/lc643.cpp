//
// Created by tooyoung on 2021/2/4.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1,0);
        double ans = INT_MIN;
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + nums[i];
            if (i >= k - 1) {
                ans = max(ans, (double) (pre[i + 1] - pre[i +1 - k]) / k);
            }
        }
        return ans;
    }
};