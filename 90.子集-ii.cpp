/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
// class Solution {
//     int sz;
//     set<vector<int>> res;
//     vector<int> t;

//     void dfs(set<vector<int>>& res,vector<int>& nums,vector<int>& t,int i){
//         if(sz==i)return;
//         t.push_back(nums[i]);
//         res.insert(t);
//         dfs(res,nums,t,i+1);
//         t.pop_back();
//         res.insert(t);
//         dfs(res,nums,t,i+1);
//     }
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         sz = nums.size();
//         sort(nums.begin(),nums.end());
//         dfs(res,nums,t,0);
//         vector<vector<int>> ans(res.begin(),res.end());
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};
// @lc code=end

