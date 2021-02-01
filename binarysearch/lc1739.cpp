//
// Created by tooyoung on 2021/2/1.
//

#include "bits/stdc++.h"
using namespace std;

//https://leetcode-cn.com/problems/building-boxes/solution/cong-fang-zhi-man-he-zi-dao-tui-qiu-jie-l7v13/
class Solution {
public:
    int minimumBoxes(int n) {
        int count = 0;
        int index = 1;
//        计算需要的最高高度index
        while (count < n) {
            count += index * (index + 1) / 2;
            index++;
        }
        index -= 1;
//        res 代表当前所占地的盒子个数
        int res = index * (index + 1) / 2;
        while (count >= n) {
            count -= index;
            if (count >= n) {
                res--;
            }
            index -= 1;
        }
        return res;
    }
};