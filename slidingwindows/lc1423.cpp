//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ans = 0;
        int n = cardPoints.size();

        vector<int> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + cardPoints[i];
        }
        int i = 0;
        while (i <= k) {
            int sum = pre[i] + pre[n] - pre[n - k + i];
            ans = max(ans, sum);
            i++;
        }
        return ans;
    }
};