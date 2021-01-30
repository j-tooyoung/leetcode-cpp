//
// Created by tooyoung on 2021/1/27.
//

#include "bits/stdc++.h"
using namespace std;
//https://leetcode-cn.com/problems/check-if-it-is-a-good-array/solution/shu-xue-he-365-shui-hu-wen-ti-lei-si-python-by-fe-/
// 裴蜀定理
class Solution {
public:
    bool isGoodArray(vector<int> &nums) {
        int a = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            a = gcd(a, nums[i]);
        }
        return a == 1;
    }
};