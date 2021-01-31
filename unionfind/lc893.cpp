//
// Created by tooyoung on 2021/1/31.
//
#include "bits/stdc++.h"
using namespace std;
class UF{

public:
    vector<int> pa;
    vector<int> sz;
    int n;
//    当前联通分量数目
    int setCount;

    UF(int n) : sz(n, 1), pa(n), n(n), setCount(n) {
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x){
        if (pa[x] == x) {
            return x;
        }
        pa[x] = find(pa[x]);
        return pa[x];
    }

    void merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x != y) {
            if (sz[x] < sz[y]) {
                swap(x, y);
            }
            sz[x] += sz[y];
            pa[y] = x;
            setCount--;
        }
    }
};
class Solution {
public:
    bool isValid(string &s1, string &s2) {
        int n = s1.size();
        int cnt = 0;
//        vector<int> v1;
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) {
                cnt++;
                if (cnt > 2) return false;
//                v1.push_back(i);
            }
        }
//        if(cnt==0) return true;
//        if (s1[v1[0]] == s2[v1[1]] && s1[v1[1]] == s2[v1[0]]) {
//            return true;
//        }
        return true;
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        UF u(n);
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isValid(strs[i], strs[j])) {
                    u.merge(i, j);
                }
            }
        }
        return  u.setCount;
    }
};