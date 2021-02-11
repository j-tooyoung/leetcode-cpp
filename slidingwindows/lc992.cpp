//
// Created by tooyoung on 2021/2/2.
//


#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        //    Returns the number of subarrays with k or less distinct numbers.
        auto subarrays = [&A](int k) -> int {
            int n = A.size();
            unordered_map<int, int> map;
            int r = 0;
            int l = 0;
            int ans = 0;
            int distinct = 0;
            while (r < n) {
                if (map.count(A[r]) == 0) {
                    distinct++;
                }
                map[A[r++]]++;

                while (distinct > k) {
                    map[A[l]]--;
                    if (map[A[l]] == 0) {
                        distinct--;
                    }
                    l++;
                }
                ans += r - l + 1;
            }
//            while (r < n) {
//                map[A[r++]]++;
//                while (map.size() > k) {
//                    map[A[l]]--;
//                    if (map[A[l]] == 0) {
//                        map.erase(A[l]);
//                    }
//                    l++;
//                }
//                ans += r - l + 1;
//            }
            return ans;
        };
        return subarrays(K) - subarrays(K - 1);
    }

    int subarraysWithKDistinct1(vector<int>& A, int K) {
        int n  = A.size();
        unordered_map<int, int> map;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                map[A[j]]++;
                if (map.size() == K) {
                    ans++;
                }
            }
        }
        return ans;

    }
};