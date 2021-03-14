//
// Created by tooyoung on 2021/3/14.
//

#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        double lo = 0, hi = 1.0;
        int n = classes.size();
        vector<vector<double>> dp(n+1, vector<double>(extraStudents + 1, 0.0));

        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k <= extraStudents; ++k) {
                for (int j = 0; j <= k; ++j) {
                    dp[i][k] = max(dp[i][k],
                                   dp[i - 1][k - j] + (classes[i-1][0] + j)* 1.0 / (j + classes[i-1][1]));
                }
            }
        }
        return dp[n ][extraStudents] / n;
    }

    /**
     * 方法一：优先队列
提示 1

「最大化平均通过率」等价于「最大化总通过率」。

提示 2

设某个班级的人数为 yy，其中可以通过考试的人数为 xx。如果给这个班级安排一个额外的学生，那么该班级的通过率会增加：

\frac{x+1}{y+1}-\frac{x}{y}
y+1
x+1
​
 −
y
x
​


提示 3

在不断地给同一个班级安排学生的过程中，增加的通过率是逐渐单调递减的，即：

\frac{x+2}{y+2}-\frac{x+1}{y+1} < \frac{x+1}{y+1}-\frac{x}{y}
y+2
x+2
​
 −
y+1
x+1
​
 <
y+1
x+1
​
 −
y
x
​


提示 4

每次选择那个可以使得通过率的增加量最大的班级放入一名学生。

思路与算法

令 \text{diff}(x, y) = \dfrac{x+1}{y+1}-\dfrac{x}{y}diff(x,y)=
y+1
x+1
​
 −
y
x
​
  表示通过率的增加量。我们将 \big( \text{diff}(x, y), x, y \big)(diff(x,y),x,y) 这一三元组放入优先队列（大根堆）中，随后进行 \textit{extraStudents}extraStudents 次操作。

每一次操作中，我们取出优先队列的堆顶元素，其对应着当前通过率的增加量最大的班级。我们将一名学生放入该班级，并将 \big( \text{diff}(x+1, y+1), x+1, y+1 \big)(diff(x+1,y+1),x+1,y+1) 放回优先队列。

最终我们可以得到「最大的总通过率增加量」，加上初始的总通过率后再除以班级数量即可得到答案。

作者：zerotrac2
链接：https://leetcode-cn.com/problems/maximum-average-pass-ratio/solution/zui-da-ping-jun-tong-guo-lu-by-zerotrac2-84br/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
     * @param classes
     * @param extraStudents
     * @return
     */
    double maxAverageRatio1(vector<vector<int>>& classes, int extraStudents) {
        int n = classes.size();
        double sum= 0;
        priority_queue<tuple<double, int, int>> pq;
        auto diff = [](int x, int y) -> double {
            return (double) (x + 1) / (y + 1) - (double) x / y;
        };
        for (const auto &v : classes) {
            double d = (v[0] * 1.0 / v[1]);
            pq.emplace(diff(v[0], v[1]), v[0], v[1]);
            sum += d;
        }

        for (int i = 0; i < extraStudents; ++i) {
            auto[di, x, y] =pq.top();
            pq.pop();
            sum += di;
            x++;
            y++;
            pq.emplace(diff(x, y), x, y);
        }
        return sum / n;
    }
};

int main(){
    cout << double(5 * 1.0 / 3) << endl;
    return  0;
}