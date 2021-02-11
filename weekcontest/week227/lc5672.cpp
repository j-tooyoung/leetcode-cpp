//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> arr(nums);
        sort(arr.begin(), arr.end());
//        int idx = find(nums.begin(), nums.end(), arr[0]) - nums.begin();
        vector<int> idxList;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] == arr[0]) {
                idxList.emplace_back(i);
            }
        }
        for (int idx : idxList) {
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (arr[i] != nums[(i + idx) % n]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }
};