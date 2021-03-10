//
// Created by tooyoung on 2021/2/15.
//

#include "bits/stdc++.h"
using namespace std;
//https://www.acwing.com/solution/LeetCode/content/27761/
// 将给定的数组里的数字构造成一棵 01 Trie 树。由于最大的数字 SS 不超过 109109 则可以规定每个不同数字占用一个叶子节点，每一层表示一个二进制位，从根节点到叶子节点经过 30 条边。
//在插入过程中，除根节点外的每个节点，都记录所有经过数字的最小值。
//查询时，从根节点开始，优先考虑与 xx 在当前层不同的分支（因为产生的结果更大）。如果不同的分支存在，且选择不同分支后，到达节点中记录的最小值小于等于 mm，则可以选择不同分支，答案累加 2h2h。
//否则，考虑相同的分支，也要经过最小值的验证。如果两个分支都不存在或者都不满足要求，则返回 -1。
struct Node {
    int mi;
    Node *next[2];
    Node() {
        mi = INT_MAX;
        next[0] = next[1] = NULL;
    }
};
class Solution {
private:
    Node *root;

    void insert(int x) {
        Node *p = root;
        for (int i = 30; i >= 0; --i) {
            int v = (x >> i) & 1;
            if (p->next[v] == NULL) {
                p->next[v] = new Node();
            }
            p = p->next[v];
            p->mi = min(p->mi, x);
        }
    }

    int query (int x, int m){
        Node *p = root;
        int res = 0;
        for (int i = 30; i >= 0; --i) {
            int v = (x >> i) & 1;
            if (p->next[v ^ 1] && p->next[v ^ 1]->mi <= m) {
                res |= 1 << i;
                p = p->next[v ^ 1];
            } else if (p->next[v] && p->next[v]->mi <= m) {
                p = p->next[v];
            }else{
                return -1;
            }
        }
        return res;
    }
public:

    vector<int> maximizeXor(vector<int> &nums, vector<vector<int>> &queries) {
        root = new Node();
        for (int x: nums) {
            insert(x);
        }
        vector<int> ans(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            int x = queries[i][0];
            int m = queries[i][1];
            ans[i] = query(x, m);
        }
        return ans;
    }
        // 暴力法
    vector<int> maximizeXor1(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> ans(n, 0);
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i) {
            int x = queries[i][0];
            int m = queries[i][1];
            int idx = lower_bound(nums.begin(), nums.end(), m+1) - nums.begin() - 1;
            if(idx <0)ans[i] =-1;
            else{
                int maxVal = INT_MIN;
                for (int j = 0; j <= idx; ++j) {
                    maxVal = max(maxVal, x ^ nums[j]);
                }
                ans[i] = maxVal;
            }
        }
        return ans;
    }
};

int main() {
    cout << (6 ^ 3) << " " <<  (6 ^ 2) << endl;
    return 0;
}
