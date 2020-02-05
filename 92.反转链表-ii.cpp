/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *h= new ListNode(-1),*p,*q,*r,*s;
        h->next = head;
        p = h;
        for(int i=0;i<m-1;i++)p=p->next;
        q = p->next; r = q->next;
        for(int i=0;i<n-m;i++){
            s = r->next;
            r->next = q;
            q = r;
            r = s;
        }
        p->next->next=r;
        p->next=q;
        p = h->next;
        delete h;
        return p;
    }
};
// @lc code=end

