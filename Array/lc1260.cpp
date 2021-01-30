//
// Created by tooyoung on 2021/1/26.
//

#include "bits/stdc++.h"
using namespace std;


class Solution {
public:
    vector <vector<int>> shiftGrid(vector <vector<int>> &grid, int k) {
        int row = grid.size();
        int col = grid[0].size();
        k %= (row * col);
        if (k == 0) {
            return grid;
        }
        deque<int> deque;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                deque.emplace_back(grid[i][j]);
            }
        }
        while (k--) {
            int num = deque.back();
            deque.emplace_front(num);
            deque.pop_back();
        }
        size_t idx = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                grid[i][j] = deque.at(idx++);
            }
        }
        return grid;
    }
};
