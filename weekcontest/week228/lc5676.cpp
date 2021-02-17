//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int cnt1 = s[0] == '0' ? 1 : 0;
        // 1 0 1 0
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                cnt1 += (s[i] == '0') ? 1 : 0;
            }else{
                cnt1 += (s[i] == '0') ? 0 : 1;
            }
        }
        // 0 1 0 1
        int cnt2 = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                cnt2 += (s[i] == '0') ? 0 : 1;
            }else{
                cnt2 += (s[i] == '0') ? 1 : 0;
            }
        }
        return min(cnt1, cnt2);
    }
};