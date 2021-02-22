//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n);
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i + 1; j < n; ++j) {
                sum += (boxes[j] == '0') ? 0 : j - i;
            }
            for (int j = 0; j < i; ++j) {
                sum += (boxes[j] == '0') ? 0 : i - j;
            }
            ans[i] = sum;
        }
        return ans;
    }
};