//
// Created by tooyoung on 2021/2/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int countHomogenous(string s) {
        int mod = 1e9 + 7;
        int n = s.size();
        long long ans = 0;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                j++;
            }
            int cnt = j - i;
            ans += (long long)(j - i) * (j - i + 1) / 2;
            ans %= mod;
            i = j;
        }
        return ans;
    }
};