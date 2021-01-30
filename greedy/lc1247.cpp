//
// Created by tooyoung on 2021/1/27.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int ans = 0;
        int len = s1.size();
        int cntX= 0;

        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s1[i] != s2[i]) {
                cntX += (s1[i] == 'x');
                cnt++;
            }
        }
        if (cnt % 2 != 0) {
            return -1;
        }
        int cntY = cnt - cntX;
        if (cntX % 2 == 0) {
            return (cntX / 2) + (cntY / 2);
        }else{
            return (cntX / 2) + (cntY / 2) + 2;
        }

    }
};