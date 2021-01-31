//
// Created by tooyoung on 2021/1/31.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries) {
        typedef long long ll;
        int n = candiesCount.size();
        vector<bool> ans;
        vector<ll> pre(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + candiesCount[i];
        }
        int size = queries.size();
        for (int i = 0; i < size; ++i) {
            int favoriteType = queries[i][0];
            int favoriteDay = queries[i][1];
            int dailyCap = queries[i][2];
            if (pre[favoriteType] >= (ll) (favoriteDay + 1) * dailyCap || favoriteDay >=pre[favoriteType+1]) {
                ans.push_back(false);
            } else {
                ans.push_back(true);
            }
        }
        return ans;
    }
};
