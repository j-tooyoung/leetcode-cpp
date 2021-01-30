//
// Created by tooyoung on 2021/1/27.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans;
        stack<char> st;

        int cnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                st.push('(');
                cnt++;
            } else if (s[i] == ')') {
                if (cnt >= 1) {
                    st.push(')');
                    cnt--;
                }
            } else {
                st.push(s[i]);
            }
        }

        while (cnt) {
            if (st.top() == '(') {
                st.pop();
                cnt--;
            }else{
                ans.push_back(st.top());
                st.pop();
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
