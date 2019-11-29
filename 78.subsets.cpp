/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    vector<int> s;
    vector<vector<int>> res;
    int len;
    void dfs(vector<int>& nums,int n){
        if(n==len){
            res.push_back(s);
            return;
        }
        dfs(nums,n+1);
        s.push_back(nums[n]);
        dfs(nums,n+1);
        s.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        len = nums.size();
        dfs(nums,0);
        return res;
    }
};
// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> subs = {{}};
//         for (int num : nums) {
//             int n = subs.size();
//             for (int i = 0; i < n; i++) {
//                 subs.push_back(subs[i]); 
//                 subs.back().push_back(num);
//             }
//         }
//         return subs;
//     }
// }; 
// @lc code=end

