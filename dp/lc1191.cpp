//
// Created by tooyoung on 2021/2/2.
//

#include "bits/stdc++.h"
using namespace std;
//解题分两种情况：
//
//k = 1: max = 最大子串
//k >= 1:
//如果数组和>0：max = 最大后子串 + (k - 2)*数组和 + 最大前子串
//如果数组和<=0：max = 最大后子串 + 最大前子串
//最后max与最大子串做对比，取最大值
//
//        作者：triggerz
//        链接：https://leetcode-cn.com/problems/k-concatenation-maximum-sum/solution/cshi-xian-he-xin-zai-onzhao-dao-zui-da-lian-xu-zi-/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int maxPre = 0;
        int maxSuffix = 0;
        int size = arr.size();
        int pre = 0;

        for (int i = 0; i < size; ++i) {
            pre += arr[i];
            maxPre = max(maxPre, pre);
        }
        pre = 0;
        for (int i = size - 1; i >= 0; --i) {
            pre += arr[i];
            maxSuffix = max(maxSuffix, pre);
        }
        // 数组最大子序和
        int cur = 0;
        int maxCur = 0;
        for (int i = 0; i < size; ++i) {
            cur = max(cur + arr[i], arr[i]);
            maxCur = max(maxCur, cur);
        }
        long long mod = 1e9+7;
        if (k == 1) {
            return maxCur;
        } else if (sum > 0) {
            return (maxPre + maxSuffix +(long long) (k - 2) * sum) %mod;
        } else {
            return max(maxPre + maxSuffix, maxCur) % mod;
        }

    }
};