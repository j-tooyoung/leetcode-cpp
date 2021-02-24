//
// Created by tooyoung on 2021/2/23.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int n = customers.size();
        int ans = 0;
        vector<int> preUnsatisySum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            ans += (grumpy[i] == 0) ? customers[i] : 0;
            preUnsatisySum[i + 1] = (grumpy[i] == 0) ? preUnsatisySum[i] : preUnsatisySum[i] + customers[i];
        }
        int maxVal = 0;
        for (int i = 0; i + X <= n; ++i) {
            maxVal = max(maxVal, preUnsatisySum[i + X] - preUnsatisySum[i]);
        }
        return ans + maxVal;
    }
};