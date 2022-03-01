/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    // 合并链表
    ListNode *merge(ListNode *L, ListNode *R){
        ListNode *dummy = new ListNode(0);
        ListNode *cur = dummy;

        while(L != nullptr && R != nullptr){
            if(L->val <= R->val){
                cur->next = L;
                L = L->next;
                cur = cur->next;
            }
            else{
                cur->next = R;
                R = R->next;
                cur = cur->next;
            }
        }
        if(L != nullptr){
            cur->next = L;
        }
        if(R != nullptr){
            cur->next = R;
        }
        return dummy->next;
    }

    // 切分链表
    ListNode *mergeSort(ListNode *head){
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode *slow = head, *fast = head;
        ListNode *pre = nullptr;
        while(fast != nullptr && fast->next != nullptr){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        ListNode *L = mergeSort(head);
        ListNode *R = mergeSort(slow);
        return merge(L, R);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};
// @lc code=end

