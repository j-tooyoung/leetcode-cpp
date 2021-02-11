//
// Created by tooyoung on 2021/2/7.
//
// 贪心 动态规划
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;

        for (int i = 1; i  < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (i >= 2 && nums[i] < nums[i - 2]) {
                    nums[i] = nums[i - 1];
                }else{
                    nums[i - 1] = nums[i];
                }
                cnt++;
            }
            if (cnt > 1) {
                return false;
            }
        }
        return cnt <= 1;
    }
};