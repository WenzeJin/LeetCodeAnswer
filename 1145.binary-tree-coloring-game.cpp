/*
 * @lc app=leetcode.cn id=1145 lang=cpp
 *
 * [1145] Binary Tree Coloring Game
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
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        // 当 x 选定后，形成父、左、右三个子树，y 只要堵住一个子树，那么这个子树就是 y 的，并且剩下两个子树就是 x 的，比较子树大小。
        TreeNode* xNode = nullptr;
        int leftSize;
        int rightSize;

        function<int(TreeNode*)> dfs = [&](TreeNode* curr)-> int {
            if (curr == nullptr) {
                return 0;
            }
            if (curr->val == x) {
                xNode = curr;
                leftSize = dfs(curr->left);
                rightSize = dfs(curr->right);
                return leftSize + rightSize + 1;
            } else {
                return dfs(curr->left) + dfs(curr->right) + 1;
            }
        };

        int treeSize = dfs(root);
        int parentSize = treeSize - leftSize - rightSize - 1;
        vector<int> choice = {parentSize, leftSize, rightSize};
        sort(choice.begin(), choice.end());
        return choice[2] > choice[1] + choice[0] + 1;
    }
};
// @lc code=end

