//
// Created by tooyoung on 2021/2/3.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int> maxQ;
        priority_queue<int> minQ;
        int n = nums.size();
        vector<double> ans(n - k + 1);
        for (int i = 0; i < n; ++i) {
            if (i <= k - 1) {
                maxQ.emplace(nums[i]);
                minQ.emplace(nums[i]);
            }else{

            }
        }
        return ans;
    }

    vector<double> medianSlidingWindow1(vector<int>& nums, int k) {

        int n = nums.size();
        // 构造初始化，否则报空指针
        vector<double> ans(n-k+1);
        vector<double> arr(nums.begin(), nums.begin() + k);
        sort(arr.begin(), arr.end());
        ans[0] = arr[k / 2] * 0.5 + arr[(k - 1) / 2] * 0.5;
        for (int i = 0; i < n - k; ++i) {
            arr.erase(find(arr.begin(), arr.end(), nums[i]));
            arr.insert(lower_bound(arr.begin(), arr.end(), nums[i + k]), nums[i + k]);
            ans.emplace_back(arr[k / 2] * 0.5 + arr[(k - 1) / 2] * 0.5);
        }
        return ans;
    }
};