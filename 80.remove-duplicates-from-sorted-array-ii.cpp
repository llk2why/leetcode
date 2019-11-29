/*
 * @lc app=leetcode id=80 lang=cpp
 *
 * [80] Remove Duplicates from Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,j,c,n=nums.size();
        if(n<=2)return n;
        for(i=j=1,c=0;i<n;i++){
            if(nums[i]==nums[j-1]){
                if(!c){
                    nums[j]=nums[i];
                    j++;
                    c=1;
                }
            }
            else{
                nums[j]=nums[i];
                j++;
                c=0;
            }
        }
        return j;
    }
};
// @lc code=end

