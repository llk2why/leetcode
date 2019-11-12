/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)return NULL;
        if(k==1)return head;
        ListNode *pk,*pkk,*q,*pre,*h,*t1,*t2,*t3;
        pre = new ListNode(-1);
        h = NULL;
        pk = pkk = pre;
        q = head;
        pre->next=head;
        bool fk=true,fkk=true;
        int i=k;
        while(i--){
            if(pkk->next)pkk=pkk->next;
            else{fkk=false;break;}
        }
        while(fk){
            i=k;
            while(i--){
                if(pk->next)pk=pk->next;
                else{fk=false;break;}
                if(pkk->next){pkk=pkk->next;}
                else{fkk=false;}
            }
            if(fk){
                t1 = q;
                q = q->next;
                if(fk&&!h)h=pk;
                if(fkk)t1->next=pkk;
                else if(fk)t1->next=pk->next;
                else t1->next=pk->next;
                pre->next=pk->next;
                while(q!=pre->next){
                    t2 = q->next;
                    q->next=t1;
                    t1=q;
                    q=t2;
                }
                pk = pre;
            }
        }
        return h?h:head;
    }
};

