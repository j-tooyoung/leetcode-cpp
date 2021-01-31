//
// Created by tooyoung on 2021/1/31.
//


#include "bits/stdc++.h"
using namespace std;

const int maxn = 2010;
bool dp[maxn][maxn];

class Solution {
public:

    bool checkPartitioning(string s) {
        memset(dp, 0, sizeof(dp));
        int n = s.length();
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j];
                }else{
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }
            }
        }

//        for (int l = 0; l < n; ++l) {
//            for (int i = 0; i + l < n; ++i) {
//                int j = i + l;
//                if (l == 0) {
//                    dp[i][j] = true;
//                } else if (l == 1) {
//                    dp[i][j] = (s.charAt(i) == s.charAt(j));
//                } else {
//                    dp[i][j] = (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]);
//                }
//            }
//        }
//
//        作者：isaaczhu
//        链接：https://leetcode-cn.com/problems/palindrome-partitioning-iv/solution/dpyu-chu-li-jian-dan-mei-ju-by-isaaczhu-dcsq/
//        来源：力扣（LeetCode）
//        著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
//        for (int i = 0; i < n; ++i) {
//            dp[i][i] = 1;
//            if (i < n - 1) {
//                if (s[i] == s[i + 1]) {
//                    dp[i][i + 1] = 1;
//                }
//            }
//        }
//        for (int len = 3; len <= n; ++len) {
//            for (int i = 0; i + len - 1 < n; ++i) {
//                int j = i + len - 1;
//                if (s[i] == s[j] && dp[i+1][j-1]==1) {
//                    dp[i][j] = 1;
//                }
//            }
//        }

        // todo
        for (int i = 0; i < n; ++i) {
            for (int j = i + 2; j  < n; ++j) {
                if (dp[0][i] && dp[i + 1][j - 1] && dp[j][n - 1]) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isPalind(string s, int lo, int hi) {
        if (lo > hi) {
            return false;
        }
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }

// 暴力法
    bool checkPartitioning1(string s) {
        int lo = 1, hi = s.size() - 2;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isPalind(s, 0, i) && isPalind(s, i+1, j) && isPalind(s, j + 1, n - 1)) {
                    return true;
                 }
            }
        }
//        while (lo < hi) {
//            if (isPalind(s, 0, lo - 1) && isPalind(s, lo, hi) && isPalind(s, hi + 1, n - 1)) {
//                return true;
//            }
//        }
        return false;
    }
};