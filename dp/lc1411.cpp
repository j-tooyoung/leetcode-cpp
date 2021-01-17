//
// Created by tooyoung on 2021/1/17.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int numOfWays(int n) {
        if(n==1) return 12;
        if(n==2) return 54;
        vector<int64_t> a{6, 30};
        vector<int64_t> b{6, 24};
        for (int i = 2; i < n; ++i) {
            a.emplace_back((3 * a[i - 1] + 2 * b[i - 1])% 1000000007);
            b.emplace_back((2 * a[i - 1] + 2 * b[i - 1]) % 1000000007);
        }
        return (a.back() + b.back()) % 1000000007;

    }
};



