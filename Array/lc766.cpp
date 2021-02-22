//
// Created by tooyoung on 2021/2/22.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            bool flag = true;
            int x = i + 1, y = 1;
            while (x < row && y < col) {
                if (matrix[x][y] != matrix[i][0]) {
                    flag = false;
                    break;
                }
                x++;
                y++;
            }
            if (!flag) {
                return false;
            }
        }
        for (int i = 0; i < col; ++i) {
            bool flag = true;
            int x = 1, y = i+1;
            while (x < row && y < col) {
                if (matrix[x][y] != matrix[0][i]) {
                    flag = false;
                    break;
                }
                x++;
                y++;
            }
            if (!flag) {
                return false;
            }
        }
        return true;
    }

    bool isToeplitzMatrix1(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int target = j >= i ? matrix[0][j - i] : matrix[i - j][0];

                if (matrix[i][j] != target) {
                    return false;
                }
            }
        }

        return true;
    }
};