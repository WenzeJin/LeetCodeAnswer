/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start


// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *pt1 = list1;
        ListNode *pt2 = list2;
        ListNode *head = new ListNode();
        ListNode *pt = head;
        while (pt1 != nullptr && pt2 != nullptr) {
            if (pt1->val < pt2->val) {
                pt->next = pt1;
                pt1 = pt1->next;
            } else {
                pt->next = pt2;
                pt2 = pt2->next;
            }
            pt = pt->next;
        }
        if (pt1 != nullptr) {
            pt->next = pt1;
        } else {
            pt->next = pt2;
        }
        return head->next;
    }
};
// @lc code=end

