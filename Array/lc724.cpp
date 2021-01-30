//
// Created by tooyoung on 2021/1/28.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int left = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int right = total - nums[i] - left;
            if (left == right) {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};