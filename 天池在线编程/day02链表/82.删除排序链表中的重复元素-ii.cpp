/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *dummy = new ListNode(-101);
        dummy->next = head;
        // pre指向前缀结点, cur指向当前结点, nxt指向后缀结点
        ListNode *pre = dummy, *cur = pre->next, *nxt = cur->next;
        while(nxt != nullptr){
            // 当前结点和后缀结点不同时, 可加入
            if(cur->val != nxt->val){
                pre->next = cur;
                pre = pre->next;
            }
            else{
                // 当后缀结点后移至与当前结点值不相同
                while(nxt != nullptr && cur->val == nxt->val){
                    nxt = nxt->next;
                }
            }
            // 当前结点指向后缀结点
            cur = nxt;
            // 后缀结点后移
            if(nxt != nullptr)
                nxt = nxt->next;
        }
        // 收尾
        pre->next = cur;
        return dummy->next;
    }
};
// @lc code=end

