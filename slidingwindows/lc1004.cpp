//
// Created by tooyoung on 2021/1/30.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int longestOnes(vector<int> &A, int K) {
        int i = 0, j = 0;
        int n = A.size();
        int cnt = 0;
        int ans = 0;
        int zeroCnt = 0;
        while (j < n) {
            // 右端点向右前进
            if (A[j] == 0) {
                zeroCnt++;
            }
//            只要窗口不满足条件，左端点向右移
            while (zeroCnt > K) {
                if (A[i] == 0) {
                    --zeroCnt;
                }
                i++;
            }

            ans = max(ans, j - i + 1);
        }

//        while (j < n) {
//            // 右端点向右前进
//            if (A[j] == 1) {
//                cnt++;
//            }
////            只要窗口不满足条件，左端点向右移
//            while (j - i + 1 - cnt > K) {
//                if (A[i] == 1) {
//                    --cnt;
//                }
//                i++;
//            }
//
//            ans = max(ans, j - i + 1);
//        }
        return ans;
    }
};