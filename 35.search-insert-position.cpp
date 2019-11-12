/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int a,b,m,v;
        a=0;b=nums.size()-1;
        if(b==-1)return 0;
        if(target>nums[b])return b+1;
        while(a<b)
        {
            m=(a+b)/2;
            v=nums[m];
            if(v==target)return m;
            else if(v>target) b=m-1;
            else a=m+1;
        }
        return nums[a]<target?a+1:a;
    }
};

