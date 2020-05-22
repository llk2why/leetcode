/*
 * @lc app=leetcode.cn id=1371 lang=cpp
 *
 * [1371] 每个元音包含偶数次的最长子字符串
 */

// @lc code=start
class Solution {
public:
    int findTheLongestSubstring(string s) {
        unordered_map<char,int> dic({
            {'a',0},
            {'e',1},
            {'i',2},
            {'o',3},
            {'u',4},
        });
        unordered_map<int,int> mp;
        mp[0]=-1;
        int n = s.size();
        int res = 0,st=0;
        for(int i=0;i<n;i++){
            char &c = s[i];
            if(dic.find(c)!=dic.end())st^=1<<dic[c];
            if(mp.find(st)==mp.end())mp[st]=i;
            else res = max(res,i-mp[st]);
        }
        return res;
    }
};
// @lc code=end

