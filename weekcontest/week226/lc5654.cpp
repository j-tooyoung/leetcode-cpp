//
// Created by tooyoung on 2021/1/31.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        unordered_map<int, int> map;
        for (int i = lowLimit; i <= highLimit; ++i) {
            int sum = 0;
            int j =i;
            while (j) {
                sum += j % 10;
                j /= 10;
            }
            map[sum]++;
        }
        int maxVal = 0;
        for (auto[k, v] : map) {
            if (v > maxVal) {
                maxVal = v;
            }
        }
        return maxVal;
    }
};