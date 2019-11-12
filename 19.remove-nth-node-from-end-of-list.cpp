/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p = new ListNode(0);
        ListNode *q=head,*h=p;
        p->next = head;
        while(--n)q = q->next;
        while(q->next){
            p = p->next;
            q = q->next;
        }
        p->next = p->next->next;
        return h->next;
    }
};

