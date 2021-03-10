//
// Created by tooyoung on 2021/3/10.
//
/**
 * 一对括号是一层，一层一层地计算
外层要等内层的解决了才能发挥作用，不能忘了外层，所以要入栈暂存
使用一个栈，计算同一“层级”的数字
当扫描到 ( ，意味着准备计算内层了，把计算好的外层结果入栈暂存
当扫描到 ) ，意味着内层的计算结束，将栈顶的元素出栈，与内层结果共同参与运算

作者：xiao_ben_zhu
链接：https://leetcode-cn.com/problems/basic-calculator/solution/si-lu-jian-dan-yi-ci-bian-li-dai-ma-jian-rzjn/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
#include "bits/stdc++.h"
using namespace std;
class Solution {
public:
    int calculate(string s) {
        long long res = 0;
        int num = 0, sign = 1;
        stack<long long> stack;
        for (auto c : s) {
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
            } else if (c == '+' || c == '-') {
                res += sign * num;
                num = 0;
                sign = c == '+' ? 1 : -1;
            } else if (c == ' ') {
                continue;
            } else if (c == '(') {
                stack.push(res);
                stack.push(sign);
                res = 0;
                sign = 1;
            } else if (c == ')') {
                res += sign * num;
                num = 0;
                res *= stack.top();
                stack.pop();
                res += stack.top();
                stack.pop();
            }
        }
        res += sign * num;
        return res;

    }
};