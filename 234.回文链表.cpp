/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 */

#include "lc_def.h"

// @lc code=start

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // 用 O(1) 空间解决这个问题，首先用快慢指针找到中点
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // 1 2 3 4 null
        //     |   |
        // 1 2 3 4 5 null
        ListNode* prev = nullptr;
        while (slow != nullptr) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        slow = prev;

        while(slow != nullptr && head != nullptr) {
            if (slow->val != head->val) {
                return false;
            }
            slow = slow->next;
            head = head->next;
        }

        return true;
    }
};
// @lc code=end

