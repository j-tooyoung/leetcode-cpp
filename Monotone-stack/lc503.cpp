//
//
// Created by tooyoung on 2021/3/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stack;
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            if (stack.empty() || stack.top() < nums[i]) {
                stack.push(nums[i]);
            }

        }
        return ans;
    }

    vector<int> nextGreaterElements1(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            bool flag = false;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    flag = true;
                    ans[i] = nums[j];
                    break;
                }
            }
        }
        return ans;
    }
};