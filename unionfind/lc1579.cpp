//
// Created by tooyoung on 2021/1/27.
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
    UF(int n): n(n), setCount(n), pa(n),sz(n,1){
        iota(pa.begin(), pa.end(), 0);
    }

    int find(int x){
        return pa[x] == x ? x : pa[x] = find(pa[x]);
    }
    bool merge(int x, int y){
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (sz[x] < sz[y]) {
            swap(x, y);
        }
        pa[y]=x;
        sz[x] += sz[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
        UF ufa(n), ufb(n);
        int ans = 0;
        for (auto &edge: edges) {
            --edge[1];
            --edge[2];
        }
        for (const auto &edge: edges) {
            if (edge[0] == 3) {
                if(!ufa.merge(edge[1],edge[2])){
                    ++ans;
                }else{
                    ufb.merge(edge[1],edge[2]);
                }
            }
        }
//独占边
        for (const auto &edge: edges) {
            if (edge[0] == 1) {
                if(!ufa.merge(edge[1],edge[2])){
                    ++ans;
                }
            }else if(edge[0]==2){
                if(!ufb.merge(edge[1],edge[2])){
                    ++ans;
                }
            }
        }
        if (ufa.setCount != 1 || ufb.setCount != 1) {
            return -1;
        }
        return ans;
    }
};