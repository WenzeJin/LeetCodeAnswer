/*
 * @lc app=leetcode.cn id=1080 lang=cpp
 *
 * [1080] Insufficient Nodes in Root to Leaf Paths
 */

#include "lc_def.h"
#include <functional>

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
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        function<bool(TreeNode*, int)> dfs = [&](TreeNode* curr, int sum) {
            if (curr->left == nullptr && curr->right == nullptr) {
                return sum + curr->val >= limit;
            }
            bool left = curr->left ? dfs(curr->left, sum + curr->val) : false;
            bool right = curr->right ? dfs(curr->right, sum + curr->val) : false;
            if (!left) curr->left = nullptr;
            if (!right) curr->right = nullptr;
            return left || right;
        };
        bool res = dfs(root, 0);
        return res ? root : nullptr;
    }
};
// @lc code=end

