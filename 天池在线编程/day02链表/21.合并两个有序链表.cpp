/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr)  return list2;
        if(list2 == nullptr)  return list1;
        // 使用头结点, 无需讨论第一个结点
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy;
        ListNode *l1 = list1, *l2 = list2;
        // 依次比较两个链表对应结点的大小, 旋转较小的.
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        // 未遍历完的链表直接加入结果最后
        if(l1 != nullptr)
            p->next = l1;
        else
            p->next = l2;
        return dummy->next;
    }
};
// @lc code=end

