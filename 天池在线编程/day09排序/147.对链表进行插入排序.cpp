/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummy = new ListNode(0); // 新建哑结点
        dummy->next = head;
        ListNode* cur = head->next; // 指向当前要移动的元素
        ListNode* p = head; // 工作指针p，每次都从头往后遍历
        ListNode* pre = dummy; // 工作指针p的前驱
        ListNode* last = head; // 指向有效元素里最后一个
        while(cur != nullptr){
            // 让p从链表头开始往后遍历，直到p==cur或者p的val大于cur的val
            pre = dummy;
            p = dummy->next;
            while(p != cur && p->val <= cur->val){
                pre = p;
                p = p->next;
            }
            // 如果p和cur相同，说明cur就应该放在当前的位置，此时新的last就是cur当前位置
            if(p == cur){
                last = cur;
                cur = cur->next; // cur指向下一个
            }
            else{
                last->next = cur->next; // 让cur处断开
                cur->next = pre->next; // 让cur链接到pre的后面
                pre->next = cur;
                cur = last->next; // 重新让cur指向待排序列第一个
            }
        }
        return dummy->next;
    }
};
// @lc code=end

