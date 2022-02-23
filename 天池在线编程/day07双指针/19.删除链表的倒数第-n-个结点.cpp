/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // 使用头结点，避免讨论第一个结点
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *first = dummy, *second = dummy;
        // 快指针先出发n步
        while(n--){
            first = first->next;
        }
        // 快慢指针保持间距n前进，直至first到达最后一个结点，此时慢结点在倒数第N个结点前一个
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }
        // 删除即可
        second->next = second->next->next;
        return dummy->next;
    }
};
// @lc code=end

