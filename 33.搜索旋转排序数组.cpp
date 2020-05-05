/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]<nums[r]){
                if(nums[mid]>target||nums[r]<target)r=mid;
                else l=mid+1;
            }
            else{
                if(nums[mid]<target||nums[l]>target)l=mid+1;
                else r=mid;
            }
        }
        if(nums.size()!=0&&nums[l]==target)return l;
        return -1;
    }
};
// @lc code=end

