/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0,n=s.size();
        if(n==0)return res;
        bool flag = false;
        for(int i=n-1;i>=0;i--){
            if(flag&s[i]==' ')break;
            if(s[i]!=' '){
                res++;
                flag=true;
            }
        }
        return res;
    }
};
// @lc code=end

