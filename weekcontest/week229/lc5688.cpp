//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

//    "cfe"
//    "ef"
    int longestPalindrome(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        for (int i = 0, j = len2 - 1; i < j; ++i, j--) {
            swap(word2[i], word2[j]);
        }
        int maxLen = max(len1,len2);
        int dp[maxLen + 1][maxLen + 1];
        for (int i = 0; i <= len1; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i <= len2; ++i) {
            dp[0][i] = 0;
        }
        int mem1[len1];
        int mem2[len2];
// 寻找word1前是否有字符串，word2后是否有字符串，
        int ans = 0;
        for (int i = 1; i <= len1; ++i) {
            dp[i][i] =1;
            for (int j = 1; j <= len2; ++j) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        return dp[len1][len2] == 0 ? 0 : 2 * dp[len1][len2] + 1;
    }

    int longestPalindrome1(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        word1 += word2;
        int len = len1 + len2;
        vector<vector<int>> dp(len, vector<int>(len, 0));
        for (int i = 0; i < len; ++i) {
            dp[i][i] = 1;
        }
        if (len == 0) {
            return 0;
        }
        int ans = 0;
        for (int i = len - 1; i >= 0; --i) {
            for (int j = i + 1; j < len; ++j) {
                if (word1[i] == word1[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
//                    放在这里去结果，判断非空
                    if (i < len1 && j >= len1) {
                        ans = max(ans, dp[i][j]);
                    }
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }

            }
        }
        return ans;
    }
};