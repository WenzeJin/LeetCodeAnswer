/*
 * @lc app=leetcode.cn id=2096 lang=cpp
 *
 * [2096] Step by step directions from a binary tree node to another
 */

#include <string>
#include <deque>
#include <sstream>
#include "lc_def.h"

using namespace std;

// @lc code=start
class Solution {
    TreeNode* lca(TreeNode* curr, int p, int q) {
        if (curr == nullptr || curr->val == p || curr->val == q) {
            return curr;
        }
        auto left = lca(curr->left, p, q);
        auto right = lca(curr->right, p, q);
        if (left == nullptr) {
            return right;
        } else if (right == nullptr) {
            return left;
        } else {
            return curr;
        }
    }

    deque<char> ops;
    
    bool printPath(TreeNode* curr, int target, bool down) {
        if (curr == nullptr) {
            return false;
        }
        if (curr->val == target) {
            return true;
        }
        if (down) {
            if (printPath(curr->left, target, down)) {
                ops.push_front('L');
                return true;
            } else if (printPath(curr->right, target, down)) {
                ops.push_front('R');
                return true;
            }
        } else {
            if (printPath(curr->left, target, down) || printPath(curr->right, target, down)) {
                ops.push_back('U');
                return true;
            }
        }
        return false;
    }
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* target = lca(root, startValue,  destValue);

        stringstream ss;

        printPath(target, startValue, false);
        for (char op: ops) {
            ss << op;
        }
        ops.clear();
        printPath(target, destValue, true);
        for (char op: ops) {
            ss << op;
        }
        return ss.str();
    }
};
// @lc code=end