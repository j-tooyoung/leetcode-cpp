//
// Created by tooyoung on 2021/1/18.
//

#include "bits/stdc++.h"
using namespace std;

class UF{
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    UF(int n): parent(vector<int>(n)),rank(vector<int>(n)), count(n){
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x){
//        if (x == find(x)) {
        if (x == parent[x]) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int x, int y){
        int fx = find(x);
        int fy = find(y);
        if (fx != fy) {
            if (rank[fx] < rank[fy]) {
                swap(fx, fy);
            }
            parent[fy] = fx;
            count--;
            // 如果秩相等，将父节点秩 + 1
            if (rank[fx] == rank[fy]) rank[fx] += 1;
        }
    }

    bool connected(int x, int y){
        return find(x) == find(y);
    }

};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &acc) {
        vector<vector<string>> res;
        // 作用：存储每个邮箱属于哪个账户 ，同时 在遍历邮箱时，判断邮箱是否出现过
        // 格式：<邮箱，账户id>
        unordered_map<string, int> map;
        int n = acc.size();
        UF uf(n);
        for (int i = 0; i < n; ++i) {
            int len = acc[i].size();
            for (int j = 1; j < len; ++j) {
                string s = acc[i][j];
                if (map.find(s) == map.end()) {
                    map[s] = i;
                }else{
                    uf.merge(map[s], i);
                }
            }
        }
        // 作用： 存储每个账户下的邮箱
        // 格式： <账户id, 邮箱列表> >
        // 注意：这里的key必须是账户id，不能是账户名称，名称可能相同，会造成覆盖

        unordered_map<int, vector<string>> idxToEmailMap;
        for (auto&[k, v] :map) {
            idxToEmailMap[uf.find(v)].emplace_back(k);
        }
        for (auto&[k, v]:idxToEmailMap) {
            sort(v.begin(), v.end());
            vector<string> tmp(1, acc[k][0]);
//            tmp.emplace_back(acc[k][0]);
            tmp.insert(tmp.end(), v.begin(), v.end());
            res.emplace_back(tmp);
        }
        return res;
    }

};
