//给你一个由非负整数组成的数组 nums 。另有一个查询数组 queries ，其中 queries[i] = [xi, mi] 。 
//
// 第 i 个查询的答案是 xi 和任何 nums 数组中不超过 mi 的元素按位异或（XOR）得到的最大值。换句话说，答案是 max(nums[j] XOR
// xi) ，其中所有 j 均满足 nums[j] <= mi 。如果 nums 中的所有元素都大于 mi，最终答案就是 -1 。 
//
// 返回一个整数数组 answer 作为查询的答案，其中 answer.length == queries.length 且 answer[i] 是第 i 个
//查询的答案。 
//
// 
//
// 示例 1： 
//
// 输入：nums = [0,1,2,3,4], queries = [[3,1],[1,3],[5,6]]
//输出：[3,3,7]
//解释：
//1) 0 和 1 是仅有的两个不超过 1 的整数。0 XOR 3 = 3 而 1 XOR 3 = 2 。二者中的更大值是 3 。
//2) 1 XOR 2 = 3.
//3) 5 XOR 2 = 7.
// 
//
// 示例 2： 
//
// 输入：nums = [5,2,4,6,6,3], queries = [[12,4],[8,1],[6,3]]
//输出：[15,-1,5]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length, queries.length <= 105 
// queries[i].length == 2 
// 0 <= nums[j], xi, mi <= 109 
// 
// Related Topics 位运算 字典树 
// 👍 20 👎 0


//leetcode submit region begin(Prohibit modification and deletion)
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
};
//leetcode submit region end(Prohibit modification and deletion)
