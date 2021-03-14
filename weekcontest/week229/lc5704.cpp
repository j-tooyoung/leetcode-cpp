//
//
// Created by tooyoung on 2021/3/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size();

        unordered_map<string, int> map;
        function<int(int, int, int)> dfs = [&](int i, int j, int minVal)  {
            if (i < 0) {
                return 0;
            }
            if (j >=n ) {
                return 0;
            }
            string s = to_string(i) + "_" + to_string(j) + to_string(minVal);
            if (map.count(s)) {
                return map[s];
            }
            int ans = (j - i + 1) * minVal;
            int left = (j + 1 < n) ? dfs(i, j + 1, min(minVal, nums[j + 1])) : 0;
            int right = i >= 1 ? dfs(i - 1, j, min(minVal, nums[i - 1])) : 0;
            map[s] = max(left, max(right, ans));
            return map[s];
        };

        return dfs(k, k, nums[k]);
    }

    /**
     * 区间必须得包含下标k
那么可以从k开始向左向右寻找以 nums[k] 为最小值的好子数组：
1.nums[r] >= nums[k] : r++
2.nums[l] <= nums[k] : l--
直到左右边界都出现比nums[k]小的数，此时计算最大可能分数 res = (r - l - 1) * nums[k]
同时更新 nums[k] 为左右边界中的较大者，继续寻找以 nums[k] 为最小值的好子数组
直到 l < 0 && r == n

作者：Cyber-Space
链接：https://leetcode-cn.com/problems/maximum-score-of-a-good-subarray/solution/c-shuang-zhi-zhen-tan-xin-zui-jian-ji-zu-b3vf/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     * @param nums
     * @param k
     * @return
     */
    int maximumScore1(vector<int> &nums, int k) {
        int n = nums.size();
        int i = k, j = k;
        int ans = 0;
        while (i >= 0 || j < n) {
            while (i >= 0 && nums[i] >= nums[k]) {
                i--;
            }
            while (j < n && nums[j] >= nums[k]) {
                j++;
            }
            ans = max(ans, (j - i - 1) * nums[k]);
            if (i >= 0 && j < n) {
                nums[k] = max(nums[i], nums[j]);
            } else if (i < 0 && j < n) {
                nums[k] = nums[j];
            } else if (i >= 0 && j >= n) {
                nums[k] = nums[i];
            } else if (i < 0 && j >= n) {
                return ans;
            }
        }
        return ans;

    }
};