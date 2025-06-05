/*
 * @lc app=leetcode.cn id=2385 lang=cpp
 *
 * [2385] Amount of Time for Binary Tree to Be Infected
 */

#include "lc_def.h"
#include <vector>

using namespace std;

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ans = 0, start;

    pair<int, bool> dfs(TreeNode* node) {
        if (node == nullptr) {
            return {0, false};
        }
        auto [l_len, l_found] = dfs(node->left);
        auto [r_len, r_found] = dfs(node->right);
        if (node->val == start) {
            // 计算子树 start 的最大深度
            // 注意这里和方法一的区别，max 后面没有 +1，所以算出的也是最大深度
            ans = max(l_len, r_len);
            return {1, true}; // 找到了 start
        }
        if (l_found || r_found) {
            // 只有在左子树或右子树包含 start 时，才能更新答案
            ans = max(ans, l_len + r_len); // 两条链拼成直径
            // 保证 start 是直径端点
            return {(l_found ? l_len : r_len) + 1, true};
        }
        return {max(l_len, r_len) + 1, false};
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        this->start = start;
        dfs(root);
        return ans;
    }
};

// @lc code=end

