//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> map;
        int ans = 0;
        for (auto num : nums) {
            map[num]++;
        }
        for (auto[k, v] : map) {
            ans += (v - 1) * v / 2;
        }
        return ans;
    }
};