//
// Created by tooyoung on 2021/2/2.
//


#include "bits/stdc++.h"
using namespace std;

// https://leetcode-cn.com/problems/ugly-number-iii/solution/er-fen-fa-si-lu-pou-xi-by-alfeim/
class Solution {
public:
    using LL = long long;
    int nthUglyNumber(int n, int a, int b, int c) {
//        unordered_set<int> set;
//        int ans = min(a, min(b, c));
//        int cntOfa = 1;
//        int cntOfb = 1;
//        int cntOfc = 1;
//
//        while (n) {
//
//        }
//        return ans;
        LL low = min(min(a, b), c);
        LL high = static_cast<LL>(low) * n;
        if (a == 1 || b == 1 || c == 1) {
            return n;
        }
        long lcmAB = lcm<long>(a, b);
        long lcmAC = lcm<long>(a, c);
        long lcmBC = lcm<long>(c, b);
        long lcmtotal = lcm<long>(lcmAB, c);

        while (low < high) {
            int mid = low + high >> 1;
            int count = mid / a + mid / b + mid / c - mid / lcmAB - mid / lcmAC - mid / lcmBC + mid / lcmtotal;
            if (count >= n) {
                high = mid;
            }else{
                low = mid + 1;
            }
        }
        return low;
    }
};