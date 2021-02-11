//
// Created by tooyoung on 2021/1/30.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isVaild(unordered_map<char, int> m1, unordered_map<char, int> m2) {
        for (auto[k, v]:m1) {
            if (v != m2[k]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> s1CountMap;
        unordered_map<char, int> s2CountMap;
        int meetCnt = 0;
        for (auto ch:s1) {
            s1CountMap[ch]++;
        }
        int n1 = s1.size();
        int n2 = s2.size();
        if (n1 > n2) {
            return false;
        }

        int left = 0;
        int right = 0;
//        固定s1的字符串窗口
        while (right < n1) {
            s2CountMap[s2[right]]++;
            right++;
        }
        while (right < n2) {
            // todo improve speed
            if (isVaild(s1CountMap, s2CountMap)) {
                return true;
            }
            s2CountMap[s2[left]]--;
            s2CountMap[s2[right]]++;
            left++;
            right++;
        }
        return isVaild(s1CountMap, s2CountMap);
    }

    bool checkInclusion1(string s1, string s2) {

    }
};

