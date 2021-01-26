//
// Created by tooyoung on 2021/1/26.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> map;
        for (auto &domine:dominoes) {
            int a = domine[0];
            int b = domine[1];
            int sum = 0;
            if (a > b) {
                swap(a, b);
            }
            sum = a * 10 + b;
            map[sum]++;
        }
        int res = 0;
        for (auto [k, v]: map) {
            res += (v - 1) * v / 2;
        }
        return res;
    }
};