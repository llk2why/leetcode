/*
 * @lc app=leetcode.cn id=410 lang=cpp
 *
 * [410] 分割数组的最大值
 */

// @lc code=start
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long l=nums[0],h=0;
        for(auto &v:nums){
            h+=v;
            l = l>v?l:v;
        }
        while(l<h){
            long long t=0,mid = (l+h)/2;
            int cnt=1; //counter has to be initialized as 1
            for(auto &v:nums){
                t+=v;
                if(t>mid){
                    t=v;
                    cnt++;
                }
            }
            if(cnt>m)l=mid+1;
            else h=mid;
        }
        return h;
    }
};
// @lc code=end

