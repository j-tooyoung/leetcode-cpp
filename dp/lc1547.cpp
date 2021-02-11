//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // todo ?
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        int size = cuts.size();

        vector<vector<int>> dp(size , vector<int>(size , INT_MAX / 2));
        for(int i =0; i+1< size;i++){
            dp[i][i+1]=0;
        }
        for (int i = size-2 ; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                for (int k = i + 1; k < j; ++k) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j ] - cuts[i]);
                }
            }
        }
        return dp[0][size-1];
    }
};