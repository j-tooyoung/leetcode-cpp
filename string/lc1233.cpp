//
// Created by tooyoung on 2021/1/27.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        unordered_map<string, bool> map;
        sort(folder.begin(), folder.end());
        for (auto s : folder) {
            string str;
            bool flag = false;
            for (int i = 0; i < s.size();) {
                str += '/';
                i++;
                while (i < s.size() && s[i] != '/') {
                    str += s[i++];
                }
                if (map.count(str)) {
                    flag = true;
                    break;
                }
            }
            map[s] = true;
            if (!flag) {
                res.emplace_back(s);
            }
        }
        return res;
    }
};