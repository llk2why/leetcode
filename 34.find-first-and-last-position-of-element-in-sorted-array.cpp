/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // 两次二分查找
        vector<int> res;
        int a,b,m,v,t,tmp=-1;
        a=0;b=nums.size()-1;t=target;
        while(a<=b){
            m=(a+b)/2;
            v = nums[m];
            if(v==t)tmp=m;
            if(v>=t){
                b=m-1;
            }
            else a=m+1;
        }
        if(tmp==-1)return vector<int>({-1,-1});
        res.push_back(tmp);
        a=0;b=nums.size()-1;
        while(a<=b){
            m=(a+b)/2;
            v = nums[m];
            if(v==t)tmp=m;
            if(v<=t){
                a=m+1;
            }
            else b=m-1;
        }
        res.push_back(tmp);
        return res;
    }
};

