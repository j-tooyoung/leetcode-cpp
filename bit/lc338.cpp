//
// Created by tooyoung on 2021/2/5.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; ++i) {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }

    vector<int> countBits1(int num) {
        vector<int> ans;
        for (int i = 0; i <= num; ++i) {
            ans.push_back(__builtin_popcount(i));
        }
        return ans;
    }
};