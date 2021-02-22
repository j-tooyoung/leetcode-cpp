//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        int i = 0, j = 0;
        int wordLen1 = word1.size();
        int wordLen2 = word2.size();
        while (i < wordLen1 && j < wordLen2) {
//            char c1 = ((i < wordLen1) ? word1[i] : '');
//            char c2 = (j < wordLen2 ? word2[j] : '');
            ans += word1[i];
            ans += word2[j];
            i++;
            j++;
        }
        if (i < wordLen1) {
            ans += word1.substr(i);
        }

        if (j < wordLen2) {
            ans += word2.substr(j);
        }

        return ans;
    }
};