//
// Created by tooyoung on 2021/2/20.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> map;
        unordered_map<int, int> indexMap;
        int maxVal = INT_MIN;
        int idx = 0;
        for (int num : nums) {
            indexMap[num] = idx;
            map[num]++;
            maxVal = max(maxVal, map[num]);
            idx++;
        }
        int ans = INT_MAX;
        int n = nums.size();
        vector<int> v;
        set<int> set;
        for (int i = 0; i < n; ++i) {
            if (map[nums[i]] == maxVal && !set.count(nums[i])) {
                v.push_back(i);
                set.insert(nums[i]);
            }
        }
        for (int index :v) {
            ans = min(ans, indexMap[nums[index]] - index + 1);
        }
        return ans;
    }
};