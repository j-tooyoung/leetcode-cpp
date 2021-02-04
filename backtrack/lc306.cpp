//
// Created by tooyoung on 2021/2/4.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:

    string twoSum(string s1, string s2) {
        string ans;
        int i = s1.size() - 1;
        int j = s2.size() - 1;
        int cur = 0;
        while (i >= 0 || j >= 0) {
            cur += ((i >= 0) ? s1[i--] - '0' : 0) + ((j >= 0) ? s2[j--] - '0' : 0);
            ans.push_back(cur % 10 + '0');
            cur /= 10;
        }
        if(cur >0) ans.push_back(cur % 10 + '0');
        reverse(ans.begin(), ans.end());
        // cout<< ans << endl;
        return ans;
    }

    bool dfs(string num, int start, vector<string> &vector) {
        if (start > num.size()) {
            return false;
        }
        if (start == num.size()) {
            return vector.size() >= 3;
        }
        for (int i = start; i < num.size(); ++i) {
            //
            if (num[start] == '0' && i > start) {
                break;
            }
            int size = vector.size();
            // int s = atoi(num.substr(start, i - start + 1).c_str());
//            int s = stold(num.substr(start, i - start + 1));
            string s = num.substr(start, i - start + 1);
            if (size >= 2 && s >twoSum(vector[size - 1] , vector[size - 2]) ) {
                break;
            }
            if (size < 2 || s == twoSum(vector[size - 1] , vector[size - 2])) {
                vector.push_back(s);
                if (dfs(num, i + 1, vector)) {
                    return true;
                }
                vector.pop_back();
            }
        }
        return false;
    }

    bool isAdditiveNumber(string num) {
        vector<string> vc;
        return dfs(num, 0, vc);
    }
};