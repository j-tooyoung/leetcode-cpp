//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    //超时
    int minDays(int n) {
        vector<int> dp(n + 1, INT_MAX / 2);
        dp[0] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i] = min(dp[i - 1] + 1, dp[i]);
            if (i % 2 == 0) {
                dp[i] = min(dp[i], dp[i - i / 2] + 1);
            }
            if (i % 3 == 0) {
                dp[i] = min(dp[i], dp[i - 2 * i / 3] + 1);
            }
        }
        return dp.back();
    }

    // bfs
    int minDays1(int n) {
        queue<int> queue;
        set<int> set;
        // set.insert(n);
        queue.push(n);
        int ans = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                int num = queue.front();
                queue.pop();
                // cout << num << " ";
                if (num == 0) {
                    return ans;
                }

                if (!set.count(num - 1)) {
                    queue.push(num - 1);
                    set.insert(num - 1);
                }
                if (num % 2 == 0) {
                    if (!set.count(num / 2)) {
                        queue.push(num / 2);
                        set.insert(num / 2);
                    }
                }
                if (num % 3 == 0) {
                    if (!set.count(num / 3)) {
                        queue.push(num / 3);
                        set.insert(num / 3);
                    }
                }
            }
            // cout << endl;
            ans++;
            // cout <<"size :: " << size << " "<< ans<< " " << endl;
        }
        return ans;
    }

    int minDays3(int n) {
        queue<int> queue;
        unordered_set<int> set;
        // set.insert(n);
        queue.push(n);
        int ans = 0;
        while (!queue.empty()) {
            int num = queue.front();
            queue.pop();
            if (num == 0) {
                return ans;
            }
            if (num % 2 == 0 && set.insert(num / 2).second) {
                queue.push(num / 2);
            }
            if (num % 3 == 0 && set.insert(num / 3).second) {
                queue.push(num / 3);
            }
            if (set.insert(num - 1).second) {
                queue.push(num - 1);
            }
            ans++;
        }
        return ans;
    }

//    dfs
    int minDays2(int n) {

    }
};