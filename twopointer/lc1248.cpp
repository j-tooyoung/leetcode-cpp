//
// Created by tooyoung on 2021/1/27.
//

#include "bits/stdc++.h"
using namespace std;
// 滑动窗口 两数之和
class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        vector<int> pre(nums.size() + 1, 0);
        unordered_map<int, int> map;
        map[0] = 1;
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            pre[i + 1] = pre[i] + nums[i] % 2;
            if (map.count(pre[i + 1] - k)) {
                ans += map[pre[i + 1] - k];
            }
            map[pre[i + 1]]++;
        }
        return ans;
    }
};
