//
// Created by tooyoung on 2021/1/27.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
//暴力搜索
//    int cnt = 0;
//     void dfs(int idx, int step, int arrLen) {
//         if (idx < 0 || idx >= arrLen) {
//             return;
//         }
//         if(step<0) return;
//         if (step == 0 && idx == 0) {
//             cnt++;
//         }
//         dfs(idx + 1, step - 1, arrLen);
//         dfs(idx - 1, step - 1, arrLen);
//                 dfs(idx , step - 1, arrLen);

//     }

//     int numWays(int steps, int arrLen) {
//         dfs(0, steps, arrLen);

//         return cnt;
//     }
    unordered_map<string, int> map;
    int mod = 1e9 + 7;
    int dfs(int idx, int step, int arrLen) {
        if (idx < 0 || idx >= arrLen || step<0) {
            return 0;
        }
        string s = to_string(idx) + "," + to_string(step);
        if (map.count(s)) {
            return map[s];
        }
        if (step == 0 && idx == 0) {
//            cnt++;
            return 1;
        }
        int ans = 0;
        ans = (ans + dfs(idx + 1, step - 1, arrLen)) % mod;
        ans = (ans + dfs(idx - 1, step - 1, arrLen)) % mod;
        ans = (ans + dfs(idx, step - 1, arrLen)) % mod;
        map[s] = ans;
        return ans;
    }

    int numWays(int steps, int arrLen) {
        return dfs(0, steps, arrLen);
//        return cnt;
    }

    // 
    int numWays1(int steps, int arrLen) {
        int pos = steps / 2;
        vector<vector<int>> dp;
        for (int i = 0; i <= pos; ++i) {
            for (int j = 0; j < ; ++j) {
                
            }
        }
    }
};