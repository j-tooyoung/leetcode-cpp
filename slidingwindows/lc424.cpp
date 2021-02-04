//
// Created by tooyoung on 2021/2/2.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int, int> map(26);
        int left = 0;
        int right = 0;
        int n = s.length();
        int ans = 0;
        int curMaxCnt = 0;

        while (right < n) {
            map[s[right] - 'A']++;
            // 比较之前记录的最大数 和 当前字符的数量
            curMaxCnt = max(curMaxCnt, map[s[right] - 'A']);
            while (curMaxCnt + k < right - left + 1) {
                map[s[left] - 'A']--;
                left++;
            }
            // 符合条件
            ans = max(ans, right - left + 1);
            right++;
        }
        return ans;


    }
};