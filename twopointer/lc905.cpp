//
// Created by tooyoung on 2021/1/18.
//

//思路：指针i从左向右扫描数组。
//指针r形成区间[0,r)，放置扫描得到的偶数。r <= i。
//区间[r,i)放置的一定是奇数。
//
//当A[i]为偶数时，交换A[r]和A[i]，r++，i++。区间[0,r)依然放置偶数。区间[r,i)依然放置奇数。
//当A[i]为奇数时，i++。区间[r,i)依然放置奇数。
//
//作者：jason-2
//链接：https://leetcode-cn.com/problems/sort-array-by-parity/solution/sao-miao-fa-by-jason-2-3/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int i = 0, j = 0;
        int n = A.size();
        while (j < n) {
            if (A[j] & 1) {
                j++;
            }else{
                swap(A[i++], A[j++]);
            }
        }
        return A;
    }
    // 法 2： 两端逼近
};