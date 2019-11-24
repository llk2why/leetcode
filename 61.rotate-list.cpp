/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0||!head||!(head->next))return head;
        int len = 1;
        ListNode *p,*q,*x,*y,*t;
        p=q=head;
        while(q->next){
            q=q->next;
            len++;
        }
        if(k%len==0)return head;
        k = k%len;
        x = p;
        y = p;
        for(int i=1;i<k;i++)y=y->next;
        while(y!=q){
            t=x;
            x=x->next;
            y=y->next;
        }
        q->next = head;
        t->next = NULL;
        return x;
    }
};
// @lc code=end

