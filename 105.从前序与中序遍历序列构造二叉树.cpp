/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    inline int find(vector<int>& inorder,int is,int ie,int t){
        for(int i=is;i<=ie;i++)if(inorder[i]==t)return i;
        return -1;
    }
    void rebuild(TreeNode *&root,vector<int>& preorder,vector<int>& inorder,int ps,int pe,int is,int ie){
        if(ps>pe){root=NULL;return;}
        root = new TreeNode(preorder[ps]);
        int pos = find(inorder,is,ie,preorder[ps]);
        int len = pos-is;
        rebuild(root->left,preorder,inorder,ps+1,ps+len,is,pos-1);
        rebuild(root->right,preorder,inorder,ps+len+1,pe,pos+1,ie);
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = NULL;
        int n = preorder.size();
        if(n==0)return root;
        rebuild(root,preorder,inorder,0,n-1,0,n-1);
        return root;
    }
};
// @lc code=end

