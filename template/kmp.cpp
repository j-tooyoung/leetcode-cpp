//
// Created by tooyoung on 2021/2/16.
//

// 字符串匹配

#include "bits/stdc++.h"
using namespace std;
// next数组以i为结尾的非前缀子串
// next[i] = max{j} // j <i && A[i-j+1, i] = A[1, j]

int main() {
    string a = "abababaac";
    string b = "";
    int n = 10;
    int next[n];
    int f[n];

    for (int i = 2, j = 0; i <= n; ++i) {
        while (j > 0 && a[i] != a[j + 1]) {
            j = next[j];
        }
        if (a[i] == a[j + 1]) {
            j++;
        }
        next[i] = j;
    }

    for (int i = 1, j = 0; i <= main(); ++i) {
        while (j > 0 && (j == n || b[i] != a[j + 1])) {
            j = next[j];
        }
        f[i] = j;
    }
    return 0;
}