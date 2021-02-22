//
// Created by tooyoung on 2021/2/6.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.size();
        for (int i = 0; i < n; ++i) {
        }
        int maxVal = INT_MIN;
        int len = 0;
        int startIdx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                bool flag = true;
                unordered_map<char, int> map;
                for (int k = i; k <= j; ++k) {
                    map[s[k]]++;

                }
                for (int k = i; k <= j; ++k) {
                    if (s[k] >= 'a' && s[k] <= 'z') {
                        if (map.find(s[k] + 'A' - 'a') == map.end()) {
                            flag = false;
                        }
                    }
                    if (s[k] >= 'A' && s[k] <= 'Z') {
                        if (map.find(s[k] - 'A' + 'a') == map.end()) {
                            flag = false;
                        }
                    }
                }

                if (flag) {
                    if (j - i + 1 > maxVal) {
                        maxVal = j - i + 1;
                        startIdx = i;
                    }
                }
            }
        }
        cout << maxVal << endl;
        return s.substr(startIdx, maxVal);
    }
};

int main() {
    char a = 'b';
    char b = a + 'A' - 'a';
    cout << b << endl;
    return 0;
}