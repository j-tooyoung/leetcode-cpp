//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int preimageSizeFZF(int K) {
        auto tailingZeroNum = [](long long k) {
            long long cnt = 0;
            while (k >= 5) {
                cnt += k / 5;
                k /= 5;
            }
            return cnt;
        };
//        1000000000
//        int lo = 1, hi = INT_MAX;
        long long lo = 1, hi = LONG_LONG_MAX;
        while (lo < hi) {
            // 错误
//            int mid = lo + (hi - lo) >> 1;
            long long mid = lo + ((hi - lo) / 2);
            if (tailingZeroNum(mid) >= K) {
                hi = mid;
            }else{
                lo = mid + 1;
            }
        }
        return tailingZeroNum(lo) == K ? 5 : 0;
    }
};