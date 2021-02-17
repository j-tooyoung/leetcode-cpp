//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    // todo
    bool check(vector<int> &heights, int bricks, int ladders, int mid) {
        vector<int> v;
        int n = heights.size();
        for (int i = 1; i <= mid; ++i) {
            if (heights[i] > heights[i - 1]) {
                v.push_back(heights[i] - heights[i - 1]);
            }
        }
        if (v.size() <= ladders) {
            return true;
        }
        sort(v.begin(), v.end());
        int sum = 0;

        for (int i = 0; i < v.size() - ladders; ++i) {
            sum += v[i];
            if (sum > bricks) {
                return false;
            }
        }
        return true;
    }

// fixme error 处理细节
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        vector<int> diff(n + 1, 0);
        vector<int> pre(n + 1, 0);
        for (int i = 0; i + 1 < n; ++i) {
            diff[i] = heights[i + 1] - heights[i] <= 0 ? 0 : heights[i + 1] - heights[i];
        }
        for (int i = 0; i < n; ++i) {
            pre[i + 1] = pre[i] + diff[i];
        }
        if(pre[n] < bricks) return n-1;
        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = lo + hi +1>> 1;
            if (check(heights, bricks, ladders, mid)) {
                lo = mid ;
            } else {
                hi = mid-1;
            }
            // todo
//            nth_element(diff.begin(), diff.begin() + mid - ladders, diff.begin() + mid+1);
//            int sum = pre[mid+1];
//            int k = ladders;
//            int end = mid;
//            while (k) {
//                sum -= diff[end--];
//                k--;
//            }

        }
        return lo;
    }

    int furthestBuilding1(vector<int> &heights, int bricks, int ladders) {
        // 小顶堆
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = heights.size();
        int sum = 0;
        for (int i = 1; i < n; ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff>0) {
                if (pq.empty() || pq.size() < ladders || pq.top() <= diff) {
                    pq.push(diff);
                } else {
                    sum += diff;
                }
                if (pq.size() > ladders) {
                    sum += pq.top();
                    pq.pop();
                }
            }
            cout << i << " " << sum<<endl;
            if (sum > bricks) {
                return i - 1;
            }
        }
        return sum <= bricks ? n-1:0;
    }
};
