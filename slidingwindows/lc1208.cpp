//
// Created by tooyoung on 2021/2/5.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0;
        int n = s.length();
        int cost = 0;
        int ans = 0;
        while (j < n) {
            cost += abs(s[j] - t[j]);
            while (cost > maxCost) {
                cost -= abs(s[i] - t[i]);
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};