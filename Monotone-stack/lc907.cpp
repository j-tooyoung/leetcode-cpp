//
// Created by tooyoung on 2021/1/17.
//



#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    // 暴力不行
    int sumSubarrayMins(vector<int> &arr) {
        long long ans = 0;
        int mod = 1e9 + 7;
        int size = arr.size();
        int minVal = 0x3f3f3f;
        for (int i = 0; i < size; ++i) {
            int lo = i - 1, hi = i + 1;
            while (lo >=0 && arr[lo] >= arr[i]){
                lo--;
            }
            while (hi < size && arr[hi] > arr[i]) {
                hi++;
            }
            ans += arr[i] * ((i - lo - 1) * (hi - i - 1) + (i - lo - 1) + (hi - i - 1)+1);
            // cout << arr[i] <<" " <<  ans<< endl;
            // ans %= mod;

        }
        return ans % mod;
    }

    int sumSubarrayMins1(vector<int> &arr) {
        long long ans = 0;
        int mod = 1e9 + 7;
        int size = arr.size();
        for (int i = 0; i < size; ++i) {
            int minVal = arr[i];
            for (int j = i; j < size; ++j) {
                minVal = min(minVal, arr[j]);
                ans += minVal;
                ans %= mod;
            }
        }
        return ans % mod;
    }
};