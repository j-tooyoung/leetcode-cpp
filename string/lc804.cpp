//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string strs[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--",
                           "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--",
                           "--.."};
        unordered_set<string> set;
        for (auto s: words) {
            string tmp;
            for (auto c : s) {
                tmp += strs[c - 'a'];
            }
            set.insert(tmp);
        }
        return set.size();
    }
};