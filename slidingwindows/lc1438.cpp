//
// Created by tooyoung on 2021/2/21.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int j = 0;
        int i = 0;
        int n = nums.size();
        multiset<int> multiset;
        int ans = 0;
        while (j < n) {
            multiset.insert(nums[j]);
            while (i < n && *multiset.rbegin() - *multiset.begin() > limit) {
                multiset.erase(multiset.find(nums[i++]));
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};

int main() {
    multiset<int> set;
    for (int i = 0; i < 10; ++i) {
        set.insert(rand() );
    }
    multiset<int>::iterator itr;
    for (itr = set.begin(); itr != set.end(); ++itr) {
        cout << *itr << " ";
    }
    cout << endl;
    return 0;
}