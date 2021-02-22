//
// Created by tooyoung on 2021/2/19.
//

#include "bits/stdc++.h"
using namespace std;
#define size 100000
// 区间最值，支持查询和修改操作
struct SegementTree {
    int l, r;
    int dat;
} t[size * 4];

void build(int p, int l, int r) {
    t[p].l = l;
    t[p].r = r;
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
}

void change(int p, int x, int v){
    // 找到叶节点
    if(t[p].l == t[p].r){
        t[p].dat = v;
        return;
    }
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid) {
        change(p * 2, x, v);
    }else{
        change(p * 2 + 1, x, v);
    }
    t[p].dat = max(t[p * 2].dat, t[p * 2 + 1].dat);
}
// change(1,x,v)

int query(int p, int l, int r){
    if (l <= t[p].l && r >= t[p].r) {
        return t[p].dat;
    }
    int mid = l + r >> 1;
    int val = INT_MIN;
    if (l <= mid) {
        val = max(val, query(p * 2, l, r));
    }
    if (r > mid) {
        val = max(val, query(p * 2 + 1, l, r));
    }
    return val;
}
// cout <<query(1,l,r) << endl;

int main() {
    int n = 10000;
    // 调用入口
    build(1, 1, n);

    return 0;
}