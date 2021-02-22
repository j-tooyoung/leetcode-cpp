//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool canChoose(vector<vector<int>> &groups, vector<int> &nums) {
        int i = 0;
        int n = nums.size();
        int j;
        for (j = 0; j < groups.size(); ++j) {
            bool flag = false;
            int size = groups[j].size();
            while (i + size <= n) {
                if (groups[j] == vector<int>(nums.begin() + i, nums.begin() + i +size)) {
                    i += size;
                    flag = true;
                    break;
                } else {
                    i++;
                }
            }
            if (!flag) {
                return false;
            }
        }
        return true;

    }
};