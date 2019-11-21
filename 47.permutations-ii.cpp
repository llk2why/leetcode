/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

// @lc code=start
class Solution {
private:
    vector<vector<int> > res;
    vector<bool> b;
    int l;
    void dfs(vector<int>& nums,vector<int> &t,int n){
        if(n==l){
            res.push_back(t);
            return;
        }
        int flag=-999999;
        for(int i = 0;i<l;i++){
            if(i>0&&flag==nums[i])continue;
            if(!b[i]){
                b[i]=true;
                flag = nums[i];
                t.push_back(nums[i]);
                dfs(nums,t,n+1);
                t.pop_back();
                b[i]=false;
            }
        }
        return;
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        l = nums.size();
        b.resize(l);
        for(int i=0;i<l;i++)b[i]=false;
        vector<int> t;
        dfs(nums,t,0);
        return res;
    }
};
// @lc code=end


