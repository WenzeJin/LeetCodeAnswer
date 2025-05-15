/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
 */

// @lc code=start

/*
    使用一个优先队列，可以轻松在 knlogk 时间内解决这个问题，我们只用 k 个链表的头建堆即可。
    同样我们还可以使用二分法解决这个问题，利用合并两个链表的做法，不断合并。
    时间为 k/2 * n + k/4 * 2n + k/8 * 4n ... = kn log k 复杂度是一样的，但是可以省掉一个堆的空间，代码上则会麻烦一点。
    这里要注意的是 priority_queue 默认建一个大顶堆，所以需要反转 < 的逻辑。
    而 Java 的 PriorityQueue 默认建一个小顶堆。
*/

#include <vector>
#include <queue>

using namespace std;

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

struct Status {
    int val;
    ListNode *ptr;

    Status(ListNode *ptr) {
        val = ptr->val;
        this->ptr = ptr;
    }

    bool operator < (const Status &other) const {
        return val > other.val;
    }
};

class Solution {
    priority_queue<Status> queue;
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode();
        auto pt = head;
        for (auto p : lists) {
            if (p != nullptr)
                queue.push(Status(p));
        }

        while (!queue.empty()) {
            auto ptr = queue.top().ptr;
            queue.pop();
            pt->next = ptr;
            pt = pt->next;
            auto next = ptr->next;
            if (next != nullptr) {
                queue.push(Status(next));
            }
        }
        return head->next;
    }
};
// @lc code=end

