//
// Created by tooyoung on 2021/2/1.
//

#include "bits/stdc++.h"
using namespace std;
// 差分数组
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        vector<int> res(2 * limit + 1);
        // 这里用一个差分数组来算出res，有点像求重叠区间最大值的思路
        vector<int> diff(2 * limit + 2);
        // 对于每对数字来说，在有的范围内的x，需要一次调整，有的需要两次调整
        int lo = 0;
        int hi = nums.size() - 1;
        while (lo < hi) {
            int a = nums[lo];
            int b = nums[hi];
            if (a > b) {
                swap(a, b);
            }
//            [2,a]
            diff[2] += 2;
            diff[a + 1] -= 2;
//            [a+1,a+b-1] 1次
            diff[a+1] += 1;
            diff[a + b] -= 1;
            // a+b 不更新
//  [a+b+1,b+limit]
            diff[a+b+1] += 1;
            diff[b + limit + 1] -= 1;
//  [b+limit + 1, 2*limit]
            diff[b + limit + 1] += 2;
            diff[2 * limit + 1] -= 2;
            lo++;
            hi--;
        }
        for (int i = 1; i < res.size(); ++i) {
            res[i] = res[i - 1] + diff[i];
        }

        int ans = INT_MAX;
        for (int i = 2; i <= 2*limit; ++i) {
            ans = min(ans, res[i]);
        }
        return ans;

    }
};