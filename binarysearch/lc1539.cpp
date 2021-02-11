//
// Created by tooyoung on 2021/2/9.
//
// hash
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int> &arr, int k) {
        int l = 0;
        int r = arr.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] - mid - 1 >= k) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l + k;
    }

    int findKthPositive1(vector<int> &arr, int k) {
        unordered_map<int, int> map;
        for (int num:arr) {
            map[num]++;
        }
        int i = 1;
        while (k) {
            if (!map.count(i++)) {
                k--;
            }
        }
        return i - 1;
    }
};