/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        bool flag=true;
        ListNode *p,*q=head;
        head = new ListNode(0);
        p=head;
        p->next = q;
        stack<ListNode*> s;
        while(q){
            for(int i=0;i<k&&q;i++){
                s.push(q);
                q=q->next;
            }
            if(s.size()==k){
                while(!s.empty()){
                    ListNode* cur = s.top();
                    s.pop();
                    p->next=cur;
                    p=cur;
                }
                p->next=q;
            }
            else break;
        }
        p = head->next;
        delete head;
        return p;
    }
};
// @lc code=end

