/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
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
public:
    void recoverTree(TreeNode* root) {
        TreeNode *p1=NULL,*p2=NULL,*cur=root,*pre,*t=NULL;
        while(cur){
            if(cur->left){
                pre = cur->left;
                while(pre->right&&pre->right!=cur)
                    pre = pre->right;
                if(!pre->right){
                    pre->right = cur;
                    cur = cur->left;
                    continue;
                }
                else pre->right = NULL;
            }
            if(t&&cur->val<t->val){
                if(!p1)p1=t;
                p2 = cur;
            }
            t = cur;
            cur = cur->right;
        }
        swap(p1->val,p2->val);
    }
};
// @lc code=end

