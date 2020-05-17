/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> l(n,0),r(n,0);
        for(int i=1;i<n;i++)l[i]=max(l[i-1],height[i-1]);
        for(int i=n-2;i>=0;i--)r[i]=max(r[i+1],height[i+1]);
        int res = 0;
        for(int i=1;i<n-1;i++)res+=max(min(l[i],r[i])-height[i],0);
        return res;
    }
};
// @lc code=end

