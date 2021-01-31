//
// Created by tooyoung on 2021/1/31.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        vector<int> res;
        int n = adjacentPairs.size();
        unordered_map<int, int> map;
        unordered_map<int, vector<int>> connectedmap;

        for (int i = 0; i < n; ++i) {
            map[adjacentPairs[i][0]]++;
            map[adjacentPairs[i][1]]++;
            connectedmap[adjacentPairs[i][0]].push_back(adjacentPairs[i][1]);
            connectedmap[adjacentPairs[i][1]].push_back(adjacentPairs[i][0]);
        }
        int start = 0;
        for (auto[k, v]:map) {
            if (v == 1) {
                start = k;
                break;
            }
        }
        // cout<< start<< endl;
        res.push_back(start);
        unordered_set<int> set;
        set.insert(start);
        int cnt =1;

        while (cnt <=n) {
            int num = res.back();
            for (int digit: connectedmap[num]) {
                if (set.count(digit)==0) {
                    res.push_back(digit);
                    set.insert(digit);
                    cnt++;
                }
            }
        }
        return res;

    }
};