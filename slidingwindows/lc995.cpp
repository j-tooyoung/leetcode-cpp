//
// Created by tooyoung on 2021/2/18.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // 暴力算法
    int minKBitFlips(vector<int>& A, int K) {
        int n = A.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (A[i] == 0) {
                if(i + K-1 >=n) return -1;
                for (int j = i; j < i + K; ++j) {
                    A[j] = 1 - A[j];
                }
                cnt++;
            }
        }
        return cnt;

    }

    int minKBitFlips1(vector<int> &A, int K) {
        int n = A.size();
        int ans = 0;
        queue<int> queue;
        for (int i = 0; i< n;++i) {
            if (!queue.empty() && queue.front() + K == i) {
                queue.pop();
            }
            if ((queue.size() + A[i]) % 2 == 0) {
                if (i + K > n) {
                    return -1;
                }
                queue.push(i);
                ans++;
            }

        }
        return ans;
    }
};