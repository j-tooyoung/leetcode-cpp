//
// Created by tooyoung on 2021/3/7.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    const int mod =1e9+7;
    set<int> set;
    int ans = 0;
    int numberWays(vector<vector<int>>& hats) {
        // int n =hats.size();
        // dfs(hats,0);
        int maxId=0;
        int n = hats.size();
        for(auto &v: hats){
            for(auto num : v){
                maxId = max(maxId, num);
            }
        }
        vector<vector<int>> hatsToId(maxId+1);
        for(int i = 0; i< hats.size(); i++){
            for(auto num : hats[i]){
                hatsToId[num].push_back(i);
            }
        }
        vector<vector<int>> dp(maxId+1, vector<int>(1<<n,0));
        dp[0][0]=1;
        for(int i = 1; i<= maxId; i++){
            for(int state = 0; state <(1<<n); state++){
                dp[i][state] =dp[i-1][state];
                for(int idx : hatsToId[i]){
                    if(state &(1<<idx)){
                        dp[i][state] += dp[i-1][state ^(1<<idx)];
                        dp[i][state] %=mod;
                    }
                }
            }
        }
        return dp[maxId][(1<<n)-1];
    }

    int dfs(vector<vector<int>>& hats, int idx){
        if(idx == hats.size()){
            ans =(ans +1)%mod;
            return 1;
        }
        for(int num : hats[idx]){
            if(!set.count(num)){
                set.insert(num);
                dfs(hats,idx+1);
                set.erase(num);
            }
        }
        return 0;
    }

};