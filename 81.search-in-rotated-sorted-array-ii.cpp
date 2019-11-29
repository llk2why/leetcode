/*
 * @lc app=leetcode id=81 lang=cpp
 *
 * [81] Search in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int a,b,mid,n=nums.size();
        if(n==0)return false;
        a = 0;
        b = n-1;
        while(a<=b){
            mid = (a+b)/2;
            if(nums[mid]==target)return true;
            else if(nums[a]==nums[mid]&&nums[b]==nums[mid]){
                a++;
                b--;
            }
            else if(nums[a]<=nums[mid]){
                if((nums[a]<=target)&&nums[mid]>target)b=mid-1;
                else a = mid+1;
            }
            else{
                if((nums[mid]<target)&&nums[b]>=target)a=mid+1;
                else b=mid-1;
            }
        }
        return false;
    }
};
// @lc code=end

