/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        // 至多一个结点直接返回
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *p = head, *q = head->next;
        while(q != nullptr){
            // q结点与p结点数值不同，则相连
            if(q->val != p->val){
                p->next = q;
                p = q;
                q = p->next;
            }
            // 否则q向后寻找与p不同值的
            else{
                q = q->next;
            }
        }
        // 最后给p结点一个终止的空
        p->next = nullptr;
        return head;
    }
};
// @lc code=end

