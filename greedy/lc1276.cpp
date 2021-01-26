//
// Created by tooyoung on 2021/1/26.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        if (tomatoSlices % 2 != 0) {
            return vector<int>{};
        }
        int a = tomatoSlices / 2 - cheeseSlices;
        int b = 2 * cheeseSlices - tomatoSlices / 2;
        if (a < 0 || b < 0) {
            return vector<int>{};
        }
        return vector<int>{a, b};
    }
};

