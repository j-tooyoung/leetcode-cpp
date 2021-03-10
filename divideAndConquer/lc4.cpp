//
// Created by tooyoung on 2021/2/27.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int len = n1 + n2;
        int i = 0, j = 0;
        int idx = (n1 + n2) / 2;
        int right = 0;
        int left = 0;
        while (idx-->=0) {
            left = right;
            if (i < n1 && (j >= n2 || nums1[i] < nums2[j])) {
                right = nums1[i++];
            } else {
                right = nums2[j++];
            }
        }
        // cout << left << " " << right << endl;
        return (len & 1) ? right : (left + right) / 2.0;
//        if (len & 1) {
//            return right;
//        }
//        return (left + right) / 2.0;
    }

    int getKth(vector<int> &nums1, int i, vector<int> &nums2, int j, int k) {
        // 默认第一个是小的
        int n1 = nums1.size();
        if (nums1.size() - i > nums2.size() - j) {
            return getKth(nums2, j, nums1, i, k);
        }
        if (nums1.size() == i) {
            return nums2[j + k - 1];
        }
        if (k == 1) {
            return min(nums1[i], nums2[j]);
        }
        // 左半边k/2
        int si = min(n1, i + k / 2);
        // 右半边半边k-k/2
        int sj = j + k - k / 2;
        if (nums1[si - 1] > nums2[sj - 1]) {
            return getKth(nums1, i, nums2, sj, k - (sj - j));
        }else{
            return getKth(nums1, si, nums2, j, k - (si - i));
        }
    }

// 二分法
    double findMedianSortedArrays1(vector<int> &nums1, vector<int> &nums2) {
        int total = nums1.size() + nums2.size();
        if (!(total & 1)) {
            int left = getKth(nums1, 0, nums2,0, total / 2);
            int right = getKth(nums1, 0, nums2, 0, total / 2 + 1);
            return (left + right) / 2.0;
        }
        return getKth(nums1, 0, nums2, 0, total / 2 + 1);
    }
};