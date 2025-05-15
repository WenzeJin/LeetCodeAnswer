/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }
        auto new_head = new ListNode(0, head);
        ListNode *curr = new_head;
        ListNode *next = new_head->next;
        while (next != nullptr) {
            // swap next and nnext;
            ListNode *nnext = next->next;
            if (nnext == nullptr) {
                break;
            }
            curr->next = nnext;
            next->next = nnext->next;
            nnext->next = next;
            curr = next;
            next = curr->next;
        }
        return new_head->next;
    }
};
// @lc code=end

