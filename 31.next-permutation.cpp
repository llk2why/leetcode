/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)return;
        int tmp,e=nums[nums.size()-1],i=nums.size()-1;
        while(i>0){
            if(nums[i-1]>=nums[i])i--;
            else{
                int j=i,minmax=nums[j],p=j;
                while(j<nums.size()){
                    if(nums[j]>nums[i-1]&&nums[j]<minmax){
                        minmax = nums[j];
                        p=j;
                    }
                    j++;
                }
                swap(nums[i-1],nums[p]);
                sort(nums.begin()+i,nums.end());
                break;
            }
            if(i==0)sort(nums.begin(),nums.end());
        }
    }
};

