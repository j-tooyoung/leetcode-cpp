//
// Created by tooyoung on 2021/2/9.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int n = price.size();
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        for (const auto &offer:special) {
            bool isValid = true;
            for (int i = 0; i < n; ++i) {
                if (needs[i] < offer[i]) {
                    isValid = false;
                }
            }
            if (isValid) {
                // make choices
                for (int i = 0; i < n; ++i) {
                    needs[i] -= offer[i];
                }
                res = min(res, shoppingOffers(price, special, needs) + offer.back());
//                undo choices
                for (int i = 0; i < n; ++i) {
                    needs[i] += offer[i];
                }
            }
        }
        return res;
    }
};