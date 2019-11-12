/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    struct cmp{
        bool operator()(ListNode *a,ListNode *b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *pre = new ListNode(0);
        ListNode *p = pre;
        pre->next = NULL;
        priority_queue<ListNode*,vector<ListNode*>,cmp> q;
        for(int i=0;i<lists.size();i++)
            if(lists[i])q.push(lists[i]);
        if(q.empty())return NULL;
        while(q.size()>1){
            ListNode *cur = q.top();
            q.pop();
            p->next = cur;
            p = p->next;
            if(cur->next)q.push(cur->next);
        }
        ListNode *cur = q.top();
        p->next = cur;
        return pre->next;
    }
};

