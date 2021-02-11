//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // todo need to improve
    int findBestValue(vector<int>& arr, int target) {
        int maxVal = 0;
        int n = arr.size();
        vector<int> pre(n + 1, 0);
        sort(arr.begin(), arr.end());
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + arr[i];
            maxVal = max(maxVal, arr[i]);
        }
        int diff = INT_MAX;
        int ans = 0;
        for (int i = target / n; i <= target; ++i) {
            int lowbound = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
            int sum = pre[lowbound] + (n - lowbound) * i;
            if (abs(sum - target) < diff) {
                diff = abs(sum - target);
                ans = i;
            }
        }
        return ans;

    }
};