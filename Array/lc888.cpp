//
// Created by tooyoung on 2021/2/1.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int totalA = accumulate(A.begin(), A.end(), 0);
        int totalB = accumulate(B.begin(), B.end(), 0);
        int diff = totalA - totalB;
        vector<int> res;
        unordered_map<int, int> map;
        int sizeA = A.size();
        int sizeB = B.size();
        for (int i = 0; i < sizeB; ++i) {
            map[B[i]] = i;
        }
        for (int i = 0; i < sizeA; ++i) {
            if (map.count(A[i] - diff / 2)) {
                res.push_back(A[i]);
                res.push_back(A[i] - diff / 2);
                break;
            }
        }
        return res;
    }
};