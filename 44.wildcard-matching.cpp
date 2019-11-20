/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();
        bool **dp = new bool*[2];
        for(int i=0;i<2;i++)dp[i]=new bool[n+1];
        dp[0][0]=true;
        dp[1][0]=false;
        for(int j=1;j<=n;j++)
            dp[0][j]=p[j-1]=='*'&&dp[0][j-1]?true:false;
        int row = 0;
        for(int i=1;i<=m;i++){
            row = 1-row;
            for(int j=1;j<=n;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?'){
                    dp[row][j] = dp[1-row][j-1];
                }
                else if(p[j-1]=='*'&&(dp[1-row][j]||dp[row][j-1])){
                    dp[row][j]=true;
                }
                else dp[row][j]=false;
            }
            dp[1-row][0]=false;
        }
        return dp[row][n];
    }
};
// @lc code=end

int main(){
    string s,p;
    Solution ss;
    s = "abbabaaabbabbaababbabbbbbabbbabbbabaaaaababababbbabababaabbababaabbbbbbaaaabababbbaabbbbaabbbbababababbaabbaababaabbbababababbbbaaabbbbbabaaaabbababbbbaababaabbababbbbbababbbabaaaaaaaabbbbbaabaaababaaaabb";
    p = "**aa*****ba*a*bb**aa*ab****a*aaaaaa***a*aaaa**bbabb*b*b**aaaaaaaaa*a********ba*bbb***a*ba*bb*bb**a*b*bb";
    // s = "acdcb";
    // p="a*c?b";
    s = "bbbaab";
    p="a**?***";
    bool res = ss.isMatch(s,p);
    if(res)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}