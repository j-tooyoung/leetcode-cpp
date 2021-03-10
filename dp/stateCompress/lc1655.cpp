//
// Created by tooyoung on 2021/3/7.
//


#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    bool flag = false;
    bool dfs(vector<int> &quantity, int idx, vector<int> &list) {
        if (idx == quantity.size()) {
            return true;
        }
        for (int i = list.size() - 1; i >= 0; --i) {
            //剪支
            if(i>0 && list[i] ==list[i-1]) continue;
            if (list[i] >= quantity[idx]) {
                list[i] -= quantity[idx];
                if (dfs(quantity, idx + 1, list)) {
                    flag = true;
                    return true;
                }
                list[i] += quantity[idx];
            }
        }
        return false;
    }

    bool canDistribute(vector<int> &nums, vector<int> &quantity) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }
        vector<int> list;
        for (auto[k, v] :map) {
            list.push_back(v);
        }
        sort(list.begin(), list.end());
        dfs(quantity, 0, list);
        return flag;
    }

    // https://leetcode-cn.com/problems/distribute-repeating-integers/solution/zi-ji-mei-ju-jing-dian-tao-lu-zhuang-ya-dp-by-arse/
    // ：用一个 0 - 2^{10}(=1024)0−2
    //10
    // (=1024) 的整数代表 mm 个顾客的一个子集。随后，用 dp[i][j]dp[i][j] 表示：\textit{cnt}cnt 数组中的前 ii 个元素，能否满足顾客的子集合 jj 的订单需求。
    //
    //考虑 dp[i][j]dp[i][j] 时，为了满足子集 jj 的需求，我们可以让 \textit{cnt}[i]cnt[i] 满足 jj 的某个子集 ss， 并让 \textit{cnt}[0..i-1]cnt[0..i−1] 满足子集 j-sj−s。对于特定的某个子集 ss 而言，该种方案如果可行，必然有 dp[i-1][j-s]dp[i−1][j−s] 为 truetrue，且子集 ss 的订单需求总和不超过 cnt[i]cnt[i]。
    //
    //作者：Arsenal-591
    //链接：https://leetcode-cn.com/problems/distribute-repeating-integers/solution/zi-ji-mei-ju-jing-dian-tao-lu-zhuang-ya-dp-by-arse/
    //来源：力扣（LeetCode）
    //著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    bool canDistribute1(vector<int> &nums, vector<int> &quantity) {
        unordered_map<int, int> map;
        for (auto num : nums) {
            map[num]++;
        }
        vector<int> list;
        for (auto[k, v] :map) {
            list.push_back(v);
            // cout << v << endl;
        }
//        sort(list.begin(), list.end());
        int m = quantity.size();
        vector<int> sum(1 << m, 0);
        for (int i = 0; i < (1 << m); ++i) {
            int val = 0;
            for (int j = 0; j < m; ++j) {
                if ((i >> j) & 1) {
                    val += quantity[j];
                }
            }
            sum[i] = val;
        }
        int n = list.size();
        vector<vector<bool>> dp(n, vector<bool>(1 << m, false));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < (1 << m); ++j) {
                if (i > 0) dp[i][j] = dp[i - 1][j];
                // 子集枚举
                for (int subset = j; subset; subset = ((subset - 1) & j)) {
                    if (sum[subset] <= list[i]) {
                        // cout << sum[subset] << " " << subset<<" " << list[i] << endl;
                        if (dp[i][j]) break;
                        dp[i][j] = i >= 1 ? dp[i - 1][j - subset] : sum[j] <= list[0];
                    }
                }
            }
        }
        return dp[n - 1][(1 << m) - 1];
    }
};