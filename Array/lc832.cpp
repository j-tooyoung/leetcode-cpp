//
// Created by tooyoung on 2021/2/24.
//

#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A) {
        int row = A.size();
        int col = A[0].size();
        for (int i = 0; i < row; ++i) {
            int left = 0, right = col - 1;
            while (left < right) {
                A[i][left] = 1 - A[i][left];
                A[i][right] = 1 - A[i][right];
                swap(A[i][left], A[i][right]);
                left++;
                right--;
            }
            if (left == right) {
                A[i][left] = 1 - A[i][left];
            }
        }
        return A;
    }
};