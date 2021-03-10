//
// Created by tooyoung on 2021/2/22.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        for (int i = 0; i < s.size(); ++i) {
            vector<int> cnt(26, 0);
            for (int j = i; j < s.size(); ++j) {
                cnt[s[j] - 'a']++;
                bool flag = true;
                for (int l = 0; l < 26; ++l) {
                    if (cnt[l] < k && cnt[l] > 0) {
                        flag = false;
                        break;
                    }
                }
                if (flag) res = max(res, j - i + 1);
            }
        }
        return res;
    }

    int longestSubstring1(string s, int k) {

//        if (s.size() == 0 || s.size() < k) {
//            return 0;
//        }
//        unordered_map<char, int> map;
//        for (auto ch :s) {
//            map[ch]++;
//        }
//        int idx = 0;
//        while (idx < s.size() && map[s[idx]] >= k) {
//            idx++;
//        }
//        if (idx == s.size()) {
//            return s.size();
//        }
//        int left = longestSubstring(s.substr(0, idx), k);
//        while (idx < s.size() && map[s[idx]] < k) {
//            idx++;
//        }
//        int right = longestSubstring(s.substr(idx + 1), k);
//        return max(left, right);

        if (s.size() == 0 || s.size() < k) {
            return 0;
        }
        unordered_map<char, int> map;
        for (auto ch :s) {
            map[ch]++;
        }
        int idx = 0;
        while (idx < s.size() && map[s[idx]] >= k) {
            idx++;
        }
        if (idx == s.size()) {
            return s.size();
        }
        int left = longestSubstring(s.substr(0, idx), k);
//        再次跳过无用数据，
        while (idx < s.size() && map[s[idx]] < k) {
            idx++;
        }
        int right = longestSubstring(s.substr(idx), k);
        return max(left, right);
    }
};