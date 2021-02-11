//
// Created by tooyoung on 2021/2/8.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
// 双向dfs
// 状压，分治
    int minAbsDifference(vector<int>& nums, int goal) {
        int n = nums.size();
        int half = n /2;
        int ls = half, rs = n-half;
        vector<int> lsum(1<<ls,0);
        vector<int> rsum(1<<rs,0);
        for(int i = 1; i< (1<<ls); i++){
            for(int j = 0; j < ls; j++){
                if((i & (1<<j))==0) continue;
                lsum[i] =lsum[i-(1<<j)] + nums[j];
                break;
            }
        }

        for(int i = 1; i< (1<<rs); i++){
            for(int j = 0; j < rs; j++){
                if((i & (1<<j))==0) continue;
                rsum[i] =rsum[i-(1<<j)] + nums[ls+j];
                break;
            }
        }
        sort(lsum.begin(),lsum.end());
        sort(rsum.begin(),rsum.end());
        int ret = INT_MAX;
        for(int x : lsum){
            ret = min(ret, abs(goal-x));
        }
        for(int x : rsum){
            ret = min(ret, abs(goal-x));
        }
        int i = 0, j =rsum.size()-1;
        while(i < lsum.size() && j>=0){
            int sum = lsum[i] + rsum[j];
            ret = min(ret,abs(goal-sum));
            if(sum > goal){
                j--;
            }else{
                i++;
            }
        }
        return ret;
    }
};