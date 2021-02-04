//
// Created by tooyoung on 2021/2/2.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int minVal = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minVal = min(minVal, arr[i] - arr[i - 1]);
        }
        for (int i = 1; i < n; ++i) {
            vector<int> tmp;
            if (minVal == arr[i] - arr[i - 1]) {
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};