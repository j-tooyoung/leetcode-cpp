//
// Created by tooyoung on 2021/2/9.
//

// https://leetcode-cn.com/problems/avoid-flood-in-the-city/solution/avoid-flood-in-the-city-by-ikaruga/
// 将晴天的日期全部记录到 set<int> zero 中
//使用 unordered_map<int, int> water 来记录每个湖泊上一次下雨的日期
//遇到晴天时先不用管抽哪个湖
//当下雨时，湖泊已经水满了时，我们可以查询到上次下雨的日期
//通过这个日期在晴天记录中查找对应的晴天日期
//51. 在有序数据中查找，用二分啦
//如果找到了，就可以使用那一天抽水，找不到就不可避免的洪水了

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> water;
        set<int> dry;
        for (int i = 0; i < n; ++i) {
            int rain = rains[i];
            if (rains[i] == 0) {
                dry.insert(i);
            } else {
                if (water.count(rains[i])) {
//                    int idx = lower_bound(dry.begin(), dry.end(), water[rains[i]]) - dry.begin();
                    auto idx = dry.lower_bound(water[rains[i]]);
                    if(idx==dry.end()) return {};
                    ans[*idx] = rain;
                    dry.erase(*idx);
                }
                water[rains[i]] = i;
                ans[i] = -1;
            }
        }
        return ans;
    }
};