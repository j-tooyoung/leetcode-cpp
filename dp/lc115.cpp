//
//
// Created by tooyoung on 2021/3/17.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        //超时
//        function<int(int, int)> dfs = [&](int i, int j) -> int {
//            if (j >= n2) {
//                return 1;
//            }
//            if (i >= n1) {
//                return 0;
//            }
//            if (s[i] == t[j]) {
//                return dfs(i + 1, j + 1) + dfs(i + 1, j);
//            } else {
//                return dfs(i + 1, j);
//            }
//
//        };

        if(n1 <n2) return 0;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (n1 - i < n2 - j) {
                return 0;
            }
            if (j >= n2) {
                return 1;
            }
            if (i >= n1) {
                return 0;
            }
            if (dp[i][j] != -1) {
                return dp[i][j];
            }
            int ans = dfs(i + 1, j);
            if (s[i] == t[j]) {
                ans+= dfs(i + 1, j + 1) ;
            }
            dp[i][j] = ans;
        };
        // 有误
//        unordered_map<string, int> map;
//        function<int(int, int)> dfs = [&](int i, int j) -> int {
//            if (j >= n2) {
//                return 1;
//            }
//            if (i >= n1) {
//                return 0;
//            }
//            string s = to_string(i) + " " + to_string(j);
//            if (map.count(s)) {
//                return map[s];
//            }
//            map[s] = dfs(i + 1, j);
//            if (s[i] == t[j]) {
//                map[s] += dfs(i + 1, j + 1);
//            }
//            return map[s];
//        };
        return dfs(0, 0);
    }
};