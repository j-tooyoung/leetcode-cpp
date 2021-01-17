//
// Created by tooyoung on 2021/1/17.
//
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string entityParser(string text) {
        vector<string> words = { "&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;" };
        vector<char> chars = { '\"', '\'', '&', '>', '<', '/' };

        string ans = "";
        int len = text.size();
        for (int i = 0; i < len; ++i) {
            if (text[i] == '&') {
                bool flag = false;
                for (int j = 0; j < words.size(); ++j) {
                    if (i + words[j].size() > len) continue;
                    // 比较两个字符串是否相等
                    if (memcmp(&text[i],&words[j][0],words[j].size()) !=0) continue;
                    ans.push_back(chars[j]);
                    flag = true;
                    i += words[j].size() - 1;
                    break;
                }
                if(flag) continue;
            }
            ans.push_back(text[i]);

        }
        return ans;
    }
};