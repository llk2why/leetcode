/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=0x80000000,imax=1,imin=1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0){
                int  t = imax;
                imax = imin;
                imin = t;
            }
            imax = max(imax*nums[i],nums[i]);
            imin = min(imin*nums[i],nums[i]);
            res = max(res,imax);
        }
        return res;
    }
};
// @lc code=end

