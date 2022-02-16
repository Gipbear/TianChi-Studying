/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr){
            return nullptr;
        }
        int cnt = 0;  // 计算结点个数
        ListNode *p = head;
        while(p != nullptr){
            p = p->next;
            cnt++;
        }
        // 循环次数取余，避免重复循环
        k = k % cnt;
        // 同样使用头结点避免讨论第一个结点的问题
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *first = dummy, *second = dummy;
        // 第一个结点先出发走k步
        while(k--){
            first = first->next;
        }
        // 再同时前进，直到first指向最后一个结点
        // 此时second将指向新的链尾
        while(first->next != nullptr){
            first = first->next;
            second = second->next;
        }
        first->next = head;  // 链尾指向链头
        head = second->next;  // 慢指针的后一个是新的链头
        second->next = nullptr;  // 慢指针是新的链尾指向空
        return head;
    }
};
// @lc code=end

