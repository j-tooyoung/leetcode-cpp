//
// Created by tooyoung on 2021/1/17.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        int res = 0;
        int len = s.size();
        int i = 0, j = 0;
        int cnta = 0;
        int cntb = 0;
        int cntc = 0;
        while (j < len) {
            if (s[j] == 'a') {
                cnta++;
            } else if (s[j] == 'b') {
                cntb++;
            }else{
                cntc++;
            }
            while (cnta >= 1 && cntb >= 1 && cntc >= 1) {
                if (s[i] == 'a') {
                    cnta--;
                } else if (s[i] == 'b') {
                    cntb--;
                }else{
                    cntc--;
                }
                res += len - j;
                i++;
            }
            j++;
        }
        return res;

    }
};

