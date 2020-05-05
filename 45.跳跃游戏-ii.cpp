/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return 0;
        int p=0,q,next=1,res=1;
        while(p+nums[p]<n-1){
            res++;
            for(int i=p;i<=p+nums[p];i++){
                if(i+nums[i]>next){
                    q=i;
                    next=max(next,i+nums[i]);
                }
            }
            p=q;
            next = p+1;
        } 
        return res;
    }
};
// @lc code=end

