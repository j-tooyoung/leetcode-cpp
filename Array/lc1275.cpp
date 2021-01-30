//
// Created by tooyoung on 2021/1/27.
// 1275. 找出井字棋的获胜者
//


#include "bits/stdc++.h"

using namespace std;

class Solution {
public:
    vector<int> dirX = {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<int> dirY = {-1, -1, -1, 0, 0, 1, 1, 1};

    int checkWin(vector<vector<int>> &matrix, int x, int y, int direction, int who, int count) {
        if (x < 0 || y < 0 || x >= 3 || y >= 3 || matrix[x][y] != who) {
            return count;
        }
        count++;
        // cout << count << " " << x << " " << y << " " << char(who) << endl;
        int dx = dirX[direction];
        int dy = dirY[direction];
        return checkWin(matrix, x + dx, y + dy, direction, who, count);
    }

    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<int>> matrix(3, vector<int>(3, 0));
        for (int i = 0; i < moves.size(); ++i) {
            int x = moves[i][0];
            int y = moves[i][1];
            matrix[x][y] = (i % 2 == 0) ? 'x' : 'o';
            int who = (i % 2 == 0) ? 'x' : 'o';
            if (i >= 4) {
                for (int j = 0; j < 8; ++j) {
                    // cout<<checkWin(matrix, x, y, j, who, 0) << " " <<checkWin(matrix, x, y, 7-j, who, 0)<<endl;
                    if (checkWin(matrix, x, y, j, who, 0) + checkWin(matrix, x, y, 7 - j, who, 0) >= 4) {
                        return who == 'x' ? "A" : "B";
                    }
                }
            }
        }
        if (moves.size() == 9) {
            return "Draw";
        }
        return "Pending";
    }
};


