/*
 * @lc app=leetcode.cn id=1110 lang=cpp
 *
 * [1110] Delete Nodes And Return Forest
 */

#include <functional>
#include <vector>
#include "lc_def.h"
#include <unordered_set>

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> del_set;
        for (int d: to_delete) {
            del_set.insert(d);
        }

        vector<TreeNode*> ans;
        function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* curr) -> TreeNode* {
            if (curr == nullptr) {
                return nullptr;
            }
            if (del_set.count(curr->val)) {
                auto left = dfs(curr->left);
                auto right = dfs(curr->right);
                if (left) ans.push_back(left);
                if (right) ans.push_back(right);
                delete curr;
                return nullptr;
            } else {
                auto left = dfs(curr->left);
                auto right = dfs(curr->right);
                curr->left = left;
                curr->right = right;
                return curr;
            }
        };

        auto rt = dfs(root);
        if (rt) ans.push_back(rt);
        return ans;
    }
};
// @lc code=end

