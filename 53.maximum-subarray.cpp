#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
    int cnt;
//solution1
    // int maxSubArray(vector<int>& nums) {
    //     int n = nums.size();
    //     vector<vector<int>> dp(n,vector<int>(2,0));
    //     dp[0][0]=0x80000000;
    //     dp[0][1]=nums[0];
    //     for(int i=1;i<n;i++){
    //         dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
    //         dp[i][1]=max(dp[i-1][1]+nums[i],nums[i]);
    //     }
    //     int res = max(dp[n-1][0],dp[n-1][1]);
    //     return res;
    // }
//solution2
    int divide_n_conquer(int left,int right,vector<int> &nums){
        if(left>=right)return nums[left];
        int mid = (left+right)/2;
        int lmax,rmax,mmax,t;
        lmax = divide_n_conquer(left,mid-1,nums);
        rmax = divide_n_conquer(mid+1,right,nums);
        mmax = nums[mid];
        t = mmax;
        for(int i=mid-1;i>=left;i--){
            t+=nums[i];
            mmax=max(t,mmax);
        }
        t = mmax;
        for(int i=mid+1;i<=right;i++){
            t+=nums[i];
            mmax = max(t,mmax);
        }
        return max(mmax,max(lmax,rmax));
    }
int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        cnt=0;
        int res = divide_n_conquer(0,n-1,nums);
        return res;
    }
};
// @lc code=end
int main(){
    int v1[]={-2,1,-3,4,-1,2,1,-5,4};
    vector<int> a(v1,v1+8);
    Solution s;
    int res = s.maxSubArray(a);
    cout<<res<<endl;
}

