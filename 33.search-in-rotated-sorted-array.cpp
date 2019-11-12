/*
 * @lc app=leetcode id=33 lang=cpp
 *
 * [33] Search in Rotated Sorted Array
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size()<1)return -1;
        if(nums.size()==1)return nums[0]==target?0:-1;
        int l,r,p,n,a,b;
        l=nums[0];
        r=nums[nums.size()-1];
        a=0;
        b=nums.size()-1;
        int val;
        if(target>=l){
            while(a<=b){
                p = (a+b)/2;
                val = nums[p];
                if(val==target)return p;
                else if(val>=l&&val<target)a=p+1;
                else if(val>target&&val>=l)b=p-1;
                else b=p-1;
            }
        }
        else if(target<=r){
            while(a<=b){
                p=(a+b)/2;
                val = nums[p];
                if(val==target)return p;
                else if(val>=l)a=p+1;
                else if(val<=r&&val<target)a=p+1;
                else b=p-1;
            }
        }
        return -1;
    }
};

