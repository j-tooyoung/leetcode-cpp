//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int ans =0;
        unordered_map<int, int> map;

        for(int num : nums){
            map[num]++;
        }
        for (auto[k, v] : map) {
            ans += (v == 1) ? k : 0;
        }
        return ans;
    }
};