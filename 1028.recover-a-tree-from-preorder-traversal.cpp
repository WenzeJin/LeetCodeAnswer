/*
 * @lc app=leetcode.cn id=1028 lang=cpp
 *
 * [1028] Recover a Tree From Preorder Traversal
 */
#include "lc_def.h"
#include <stdexcept>
#include <string>
#include <sstream>
#include <stack>

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

    string base;
    int pt;
    int currLayer;

    bool consume() {
        currLayer = 0;
        while (pt < base.length() && base[pt] == '-') {
            currLayer++;
            pt++;
        }

        if (pt == base.length()) {
            return false;
        } else {
            return true;
        }
    }

    int consumeNumber() {
        if (pt == base.length()) {
            return -1;
        }
        stringstream numstr;
        while (pt < base.length() && base[pt] >= '0' && base[pt] <= '9') {
            numstr << base[pt];
            pt++;
        }
        return stoi(numstr.str());
    }

    TreeNode* recover() {
        stack<TreeNode*> s;
        TreeNode* root = new TreeNode(consumeNumber());
        pt = 1;
        s.push(root);
        while (consume()) {
            if (currLayer > s.size()) {
                throw runtime_error("Some nodes are missing!");
            }
            while (currLayer < s.size()) {
                s.pop();
            }
            if (s.empty()) {
                throw runtime_error("Multiple root nodes!");
            }
            TreeNode* top = s.top();
            int number = consumeNumber();
            if (number <= 0) {
                throw runtime_error("wrong number");
            }
            if (top->left) {
                top->right = new TreeNode(number);
                s.push(top->right);
            } else {
                top->left = new TreeNode(number);
                s.push(top->left);
            }
        }
        return root;
    }

public:
    TreeNode* recoverFromPreorder(string traversal) {
        base = traversal;
        pt = 0;
        return recover();
    }
};
// @lc code=end

