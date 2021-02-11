//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minCostToMoveChips(vector<int> &position) {
        int odd = 0, even = 0;
        for (int i = 0; i < position.size(); ++i) {
            odd += (position[i] & 1);
            even += !(position[i] & 1);
        }
        return min(even, odd);
    }
};