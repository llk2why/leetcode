/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<1)return 0;
        int pre=nums[0],cnt=1,p=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=pre){
                nums[p]=nums[i];
                cnt++;
                p++;
                pre=nums[i];
            }
        }
        return cnt;
    }
};

