//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int n = nums.size();
        int lo = 1, hi = 1e9 + 10;
        while (lo < hi) {
            int mid = lo + hi >> 1;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] > mid) {
                    int d = (nums[i] -1)/mid;
                    // cout << nums[i] << " " << mid << " "<<d<<endl;
                    cnt += d;
                }
            }
            // cout << cnt<<endl;
            // cout <<lo << " " <<hi << " " << mid << " "<< cnt<<endl;
            if (cnt <= maxOperations) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};