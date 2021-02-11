//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string ans;
        int i = 0, j = 0;
        int word1Size = word1.size();
        int word2Size = word2.size();
        while (i < word1Size && j < word2Size) {
            if (word1[i] < word2[j]) {
                ans += word2[j++];
            } else if (word1[i] > word2[j]) {
                ans += word1[i++];
            } else {
                string s1 = word1.substr(i);
                string s2 = word2.substr(j);

                if (s1 < s2) {
                    ans += word2[j++];
                }else if (s1>=s2){
                    ans += word1[i++];
                }
            }
        }
        if (i < word1Size ) {
            ans += word1.substr(i, word1Size - i);
        }
        if (j < word2Size) {
            ans += word2.substr(j, word2Size - j);
        }
        return ans;
    }
};