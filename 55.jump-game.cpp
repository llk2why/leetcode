/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i,p,ii,mmax,n;
        n=nums.size();
        i=ii=0;
        if(nums.size()==0&&nums.size()==1)return true;
        while(true){
            p = nums[i];
            mmax=0;
            for(int j=i+1;j<=i+p&&j<n;j++){
                if(nums[j]+j>mmax){
                    ii=j;
                    mmax=nums[j]+j;
                }
            }
            i = ii;
            if(mmax>=n-1)return true;
            if(nums[i]==0)return false;
        }
    }
};
// @lc code=end

