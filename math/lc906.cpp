//
// Created by tooyoung on 2021/1/18.
//


#include "bits/stdc++.h"
using namespace std;


// todo
class Solution {
public:
    // 暴力做法
    int superpalindromesInRange(string left, string right) {

    }

    bool isPail(string s){
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};