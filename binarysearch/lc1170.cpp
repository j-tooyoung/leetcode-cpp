//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        auto frequecyCnt = [&](string s) {
            unordered_map<char, int> map;
            int cnt = 0;
            int n = s.size();
            for (int i = 0; i < n; ++i) {
                map[s[i]]++;
            }
            for (int i = 0; i < 26; ++i) {
                if (map.count('a' + i)) {
                    return map['a' + i];
                }
            }
            return cnt;
        };
        vector<int> ans;
        vector<int> wordsCnt;
        for (auto word:words) {
            wordsCnt.emplace_back(frequecyCnt(word));
        }
        sort(wordsCnt.begin(), wordsCnt.end());
        // for (auto i : wordsCnt) {
        //     cout << i << " ";
        // }
        // cout << endl;
        int n = words.size();
        for (int i = 0; i < queries.size(); ++i) {
            int cnt = frequecyCnt(queries[i]);
            // cout << cnt << endl;
//            然后lower_bound()的返回值是第一个大于等于val的值的地址，用这个地址减去first，得到的就是第一个大于等于val的值的下标
// upper_bound 返回第一个大于x的地址
            int idx = lower_bound(wordsCnt.begin(), wordsCnt.end(), cnt+1) - wordsCnt.begin();
            // cout <<cnt << " " << idx << endl;
            ans.emplace_back(n - idx);
        }
        return ans;
    }

};