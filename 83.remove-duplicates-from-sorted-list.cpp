/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    ListNode* deleteDuplicates(ListNode* head)  {
        if(!head||!head->next)return head;
        ListNode *h = new ListNode(-1);
        ListNode *i,*j,*k;
        int last;
        bool flag;
        h->next=head;
        i = h;j = head;k = head->next;
        last=head->val;
        flag=true;
        for(;k;j=k,k=k->next){
            if(flag||(last!=j->val)){
                i->next=j;
                i=j;
            }
            flag = false;
            last = j->val;
        }
        if(flag||(last!=j->val)){
            i->next=j;
            i=j;
        }
        i->next=NULL;
        return h->next;
    }
};
// @lc code=end

