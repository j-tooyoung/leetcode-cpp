//
// Created by tooyoung on 2021/1/26.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
private:
    static bool cmp(vector<int> &v1, vector<int> &v2){
        if (v1[0] == v2[0]) {
            return v1[1] > v2[1];
        }
        return v1[0] < v2[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        sort(intervals.begin(), intervals.end(), [](const vector<int> &v1,const vector<int> &v2){
//            左端点递增，右端点递减
            return v1[0] < v2[0] || (v1[0] = v2[0] && v1[1] > v2[1]);
        });

//        for (auto i = intervals.begin(); i != intervals.end(); ++i) {
//            cout << (*i)[0] << " " << (*i)[1] << endl;
//        }
        int maxRight = 0;
        int remove = 0;
        for (int i = 0; i < intervals.size(); ++i) {
            if (intervals[i][1] <= maxRight) {
                remove++;
            }else{
                maxRight = intervals[i][1];
            }
        }
        return intervals.size() - remove;
    }
};
