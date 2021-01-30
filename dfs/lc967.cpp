//
// Created by tooyoung on 2021/1/28.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> set;
        for (int i = 1; i <= 9; ++i) {
            set.insert(i);
        }
        for (int i = 1; i <= n - 1; ++i) {
            unordered_set<int> set2;
            for (auto x : set) {
                int last = x % 10;
                if (last + k < 10) {
                    set2.insert(10 *x +last + k);
                }
                if (last - k >= 0) {
                    set2.insert(10 *x +last - k);
                }
            }
            set = set2;
        }
        vector<int> ans;
        for (auto x: set) {
            ans.push_back(x);
        }
        return ans;
    }

//    // breadth frist search
//    vector<int> numsSameConsecDiff(int n, int k) {
//        deque<int> q{1, 2, 3, 4, 5, 6, 7, 8, 9};
//        if (n == 1) q.push_front(0);
//        while (--n) { // 按位扩展 (expansion by digit)
//            int sz = q.size();
//            while (sz--) {
//                int cur = q.front(); q.pop_front();
//                int l = cur % 10;
//                if (l + k < 10) q.push_back(cur * 10 + l + k);
//                if (l - k >= 0 && k) q.push_back(cur * 10 + l - k);
//            }
//        }
//        return vector<int>(q.cbegin(), q.cend());
//    }
//    // depth frist search
//    vector<int> numsSameConsecDiffII(int n, int k) {
//        vector<int> ans;
//        if (n == 1) ans.emplace_back(0);
//        for (int i = 1; i < 10; ++i)
//            dfs(n - 1, k, i, ans);
//        return ans;
//    }
//
//private:
//    void dfs(int n, int k, int cur, vector<int>& ans) {
//        if (!n) {
//            ans.emplace_back(cur);
//            return;
//        }
//        int l = cur % 10; // last digit
//        if (l + k < 10)
//            dfs(n - 1, k, cur * 10 + l + k, ans);
//        if (l - k >= 0 && k)
//            dfs(n - 1, k, cur * 10 + l - k, ans);
//    }


};