//
// Created by tooyoung on 2021/2/15.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = arr.size();
        queue<int> q;
        q.push(0);
        set<int> vis;
        vis.insert(0);
        int ans = 0;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; ++i) {
            map[arr[i]].push_back(i);
        }
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (idx == n - 1) {
                return ans;
            }
            if (idx + 1 < n && !vis.count(idx + 1)) {
                vis.insert(idx + 1);
                q.push(idx + 1);
            }
            if (idx - 1 >= 0 && !vis.count(idx - 1)) {
                vis.insert(idx - 1);
                q.push(idx - 1);
            }
            if (map.count(arr[idx]) > 1) {
                for (auto num : map[arr[idx]]) {
                    if (!vis.count(num)) {
                        vis.insert(num);
                        q.push(num);
                    }
                }

            }
            ans++;
        }
        return ans;

    }
};