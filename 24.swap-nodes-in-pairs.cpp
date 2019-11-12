/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 */
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
    ListNode* swapPairs(ListNode* head) {
        if(!head)return NULL;
        ListNode *h,*p,*q,*pre;
        pre=p=head;
        q=head->next;
        h=q?q:p;
        while(q){
            p->next = q->next;
            q->next = p;
            if(p->next){
                p=p->next;
                q=p->next;
                if(q)pre->next=q;
                else pre->next=p;
                pre = p;
            }
            else break;
        }
        return h;
    }
};

