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

    // 启发式搜索
//    随即过
    // 这个例子过不了
    // [-9014298,7566767,-914946,-2257280,8239178,-5556637,7324722,-6103364,1751734,4603195,-7295553,7969870,-9929798,6510645,2059081,-6955638,-878053,9735717,-2523152,6055974,-7750126,-3687910,-9507259,-5494812,5688988,-8798781,-2379329,-5893221,-4971163,1852649,3721357,-4412120]
    //12592323
    int minAbsDifference1(vector<int> &nums, int goal) {
        int n = nums.size();
        vector<int64_t> pos, neg;
        for (int n :nums) {
            if (n > 0) {
                pos.push_back(n);
            }else{
                neg.push_back(n);
            }
        }
        srand(time(NULL));
        int64_t ans = INT_MAX;
        int trys = 5000;
        while (trys--) {
            int64_t sum = 0;
            vector<bool> visPos(pos.size(), false);
            vector<bool> visNeg(neg.size(), false);
            int iters = pos.size() + neg.size();
            ans = min(abs((int64_t) goal - sum), ans);
            while (iters--) {
                if (sum == goal) {
                    return 0;
                }
                if (sum > goal) {
                    if (neg.empty()) {
                        break;
                    }
                    int begin = rand() % neg.size();
                    bool has = false;
                    for (int i = 0; i < neg.size(); ++i) {
                        int idx = (begin + i) % neg.size();
                        if (!visNeg[idx]) {
                            sum += neg[idx];
                            visNeg[idx] = true;
                            has = true;
                            break;
                        }
                    }
                    if (!has) {
                        break;
                    }
                }else{
                    if (pos.empty()) {
                        break;
                    }
                    int begin = rand() % pos.size();
                    bool has = false;
                    for (int i = 0; i < pos.size(); ++i) {
                        int idx = (begin + i) % pos.size();
                        if (!visPos[idx]) {
                            sum += pos[idx];
                            visPos[idx] = true;
                            has = true;
                            break;
                        }
                    }
                    if (!has) {
                        break;
                    }
                }
                ans = min(abs((int64_t) goal - sum), ans);
            }
        }
        return ans;
    }
};