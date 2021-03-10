//
// Created by tooyoung on 2021/3/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        vector<bool> can(20001);
        for (int i = 0; i < baseCosts.size(); ++i) {
            can[baseCosts[i]] = true;
        }
        toppingCosts.insert(end(toppingCosts), toppingCosts.begin(), toppingCosts.end());
        for (auto cost :toppingCosts) {
            for (int i = 20000; i >= cost; --i) {
                can[i] = can[i] | can[i - cost];
            }
        }
        int min_gap = INT_MAX;
        int ans = 0;
        for (int i = 0; i <= 20000; ++i) {
            if (can[i] && abs(i - target) < min_gap) {
                ans = i;
                min_gap = abs(i - target);
            }
        }
        return ans;

    }
};