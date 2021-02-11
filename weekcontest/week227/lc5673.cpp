//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maximumScore(int a, int b, int c) {
        if (a + b < c) {
            return a + b;
        } else if (a + c < b) {
            return a + c;
        } else if (b + c < a) {
            return b + c;
        }
        return (a + b + c) / 2;
//        queue<int[]> q;
//        int arr[3] = {a, b, c};
//        q.emplace(a, b, c);
//        int ans = 0;
//        while (!q.empty()) {
////            auto [a1, b1, c1] =q.front();
//
//        }
    }
};