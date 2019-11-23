/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        for(const auto &s :strs){
            // string s = strs[i];
            vector<int> a(100,0);
            for(const auto &c:s){
                a[c-'a']++;
            }
            mp[a].push_back(s);
        }
        vector<vector<string>> res;
        for(auto it=mp.begin();it!=mp.end();it++)
            res.push_back(it->second);
        return res;
    }
};
// @lc code=end

