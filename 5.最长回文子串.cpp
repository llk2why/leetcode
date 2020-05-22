#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string t(s.rbegin(),s.rend());
        int n=s.size();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        int len=0,p=0;
        string res="";
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    if(i==0||j==0)dp[i][j]=1;
                    else dp[i][j]=dp[i-1][j-1]+1;

                    if(dp[i][j]>len){
                        int pos = n-1-j;
                        if(pos+dp[i][j]-1==i){
                            len=dp[i][j];
                            p=i;
                        }
                    }
                }
            }
        }
        if(n) res = s.substr(p-len+1,len);
        return res;
    }
};
// @lc code=end


int main(){
    Solution s;
    string res = s.longestPalindrome("aacdefcaa");
    cout<<res<<endl;
}