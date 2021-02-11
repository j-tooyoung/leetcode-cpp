//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maxHeight(vector<vector<int>> &cuboids) {
        cuboids.push_back({0, 0, 0});
        const int n = cuboids.size();
        for (auto &box : cuboids) {
            sort(box.begin(), box.end());
        }
        sort(cuboids.begin(), cuboids.end());
        vector<int> dp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (cuboids[i][0] >= cuboids[j][0] && cuboids[i][1] >= cuboids[j][1] && cuboids[i][2] >= cuboids[j][2]) {
                    dp[i] = max(dp[i], dp[j] + cuboids[i][2]);
                }
            }
        }
        return *max_element(begin(dp), end(dp));
    }
};