//
// Created by tooyoung on 2021/2/1.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numRabbits(vector<int> &answers) {
        unordered_map<int, int> map;

        int n = answers.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (answers[i] == 0) {
                ans++;
            }
            map[answers[i]]++;
        }
        for (auto[k, v] : map) {
            if(k==0) continue;
            ans += (k + 1) * (v / (k + 1)) + (v % (k + 1) == 0 ? 0 : (k + 1));
        }

        return ans;
    }
};