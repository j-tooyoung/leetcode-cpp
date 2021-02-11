//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minimumLength(string s) {
        int i = 0, j = s.size() - 1;
        int ans = s.size();
        while (i < j) {
            if (s[i] == s[j]) {
                char tmp = s[i];
                while (i < j && s[i] == tmp) {
                    i++;
                    ans--;
                }
                if(i>=j) return 0;
                while (i < j && s[j] == tmp) {
                    j--;
                    ans--;
                }
                // cout<< s[i] << " " << s[j] << i << " " << j <<endl;
                // if(i>j) return 0;
            }else{
                break;
            }
        }
        return ans;
    }
};