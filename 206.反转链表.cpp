/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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

    ListNode* reverseList(ListNode* head) {
        ListNode *h=head,*p=NULL,*q=NULL;
        if(h)p=h->next,h->next=NULL;
        while(p){
            q = p->next;
            p->next = h;
            h = p;
            p = q;
        }
        return h;
    }
};
// @lc code=end

