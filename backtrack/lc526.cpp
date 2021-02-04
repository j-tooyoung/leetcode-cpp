//
// Created by tooyoung on 2021/2/3.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int cnt = 0;

    void dfs(int start, vector<int> &v, int n) {
        if (start > n) {
            return;
        }
        if (start == n) {
//            for (int i = 0; i <= n; ++i) {
//                cout << i << " " << v[i] << endl;
//            }
            cnt++;
            return;
        }
        for (int i = 1; i <= n; ++i) {
            if (v[i] || i % (start + 1) != 0 && (start + 1) % i != 0) {
                continue;
            }
            v[i] = 1;
            dfs(start + 1, v, n);
            v[i] = 0;
        }
    }

    int countArrangement(int n) {
        vector<int> vc(n + 1, 0);
        dfs(0, vc, n);
        return cnt;
    }
};