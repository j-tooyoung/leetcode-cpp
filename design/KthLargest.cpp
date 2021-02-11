//
// Created by tooyoung on 2021/2/11.
//

#include "bits/stdc++.h"
using namespace std;
class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int> &nums) {
        this->k = k;
        for (int num : nums) {
            pq.push(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);

       if (pq.size() > k) {
           pq.pop();
        }
        return pq.top();
    }
};