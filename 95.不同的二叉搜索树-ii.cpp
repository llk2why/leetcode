/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    void copy(TreeNode *p,TreeNode *&h){
        if(p){
            h = new TreeNode(p->val);
            copy(p->right,h->right);
            copy(p->left,h->left);
        }
        else h=NULL;
    }
    void insert(queue<TreeNode*> &q,int i){
        TreeNode *p = q.front();
        while(p->val!=i){
            q.pop();
            TreeNode *h,*sub,*t,*tt;
            h = new TreeNode(i);
            h->left = p;
            q.push(h);
            int c=0;
            for(tt=p,c=0;tt!=NULL;tt=tt->right,c++){
                h = new TreeNode(i);
                copy(p,sub);
                t = sub;
                for(int k=0;k<c;k++)t=t->right;
                h->left = t->right;
                t->right = h;
                q.push(sub);
            }
            p = q.front();
        }
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        queue<TreeNode*> res;
        vector<TreeNode*> ans;
        TreeNode *p= new TreeNode(1);
        if(n==0)return ans;
        else res.push(p);
        for(int i=2;i<=n;i++)
            insert(res,i);
        while(!res.empty()){
            ans.push_back(res.front());
            res.pop();
        }
        return ans;
    }
};
// @lc code=end

