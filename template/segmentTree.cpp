//
// Created by tooyoung on 2021/2/19.
//


#include "bits/stdc++.h"
using namespace std;
#define N 100010

// 树状数组
int c[100010];

int query(int x){
    int ans = 0;
    while (x) {
        ans + c[x];
        x -= x & -x;
    }
    return ans;
}

int add(int x, int y){
    while (x <= N) {
        c[x] += y;
        x + x & -x;
    }
}

int main () {
    return 0;
}