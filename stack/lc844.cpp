//
// Created by tooyoung on 2021/1/17.
//

//#include "string"
#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        return build(S) == build(T);
    }

    string build(string s){
        stack<char> st;
        string res;
        for (auto ch:s) {
            if (ch == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main(){
    Solution solution = *new Solution();
    cout << solution.backspaceCompare("ab#c", "ad#c");

}
