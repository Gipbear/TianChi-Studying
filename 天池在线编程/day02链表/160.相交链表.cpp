/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *la = headA, *lb = headB;
        while(la != lb){
            if(la != nullptr)
                la = la->next;
            else
                la = headB;
            if(lb != nullptr)
                lb = lb->next;
            else
                lb = headA;
        }
        return la;
    }
};
// @lc code=end

