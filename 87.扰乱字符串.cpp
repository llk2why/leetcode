/*
 * @lc app=leetcode.cn id=87 lang=cpp
 *
 * [87] 扰乱字符串
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        int sz = s1.size();
        if(sz==0)return true;
        if(sz==1)return s1==s2;
        bool dp[sz+1][sz][sz];
        for(int i=0;i<sz;i++)
            for(int j=0;j<sz;j++)
                dp[1][i][j] = s1[i]==s2[j];
        for(int len=2;len<=sz;len++){
            for(int i=0;i<=sz-len;i++){
                for(int j=0;j<=sz-len;j++){
                    dp[len][i][j]=false;
                    for(int k=1;k<len&&!dp[len][i][j];k++){
                        dp[len][i][j] = dp[len][i][j]||(dp[k][i][j]&&dp[len-k][i+k][j+k]);
                        dp[len][i][j] = dp[len][i][j]||(dp[k][i+len-k][j]&&dp[len-k][i][j+k]);
                    }
                }
            }
        }           
        return dp[sz][0][0];
    }
};
// @lc code=end

