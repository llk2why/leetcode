/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        if(!head||!(head->next))return head;
        ListNode *a,*b,*c,*d,*p;
        a=b=c=d=NULL;
        p = head;
        while(p){
            if(p->val<x){
                if(!a){a=p;b=p;}
                else{b->next=p;b=p;}
            }
            else if(p->val>=x){
                if(!c){c=p;d=p;}
                else{d->next=p;d=p;}
            }
            p=p->next;
        }
        if(a)b->next = c;
        if(c)d->next = NULL;
        return a?a:c;
    }
};
// @lc code=end

