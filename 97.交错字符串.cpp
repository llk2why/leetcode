#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<bool >> dp;
        int l1=s1.size(),l2=s2.size();
        if(l1+l2!=s3.size())return false;
        for(int i=0;i<=l1;i++){
            dp.push_back(vector<bool>(l2+1,0));
        }
        dp[0][0]=true;
        for(int i=1;i<=l1;i++)dp[i][0]=dp[i-1][0]&&(s1[i-1]==s3[i-1]);
        for(int j=1;j<=l2;j++)dp[0][j]=dp[0][j-1]&&(s2[j-1]==s3[j-1]);
        for(int i=1;i<=l1;i++){
            for(int j=1;j<=l2;j++){
                dp[i][j] = dp[i-1][j]&&(s1[i-1]==s3[i+j-1]);
                dp[i][j] = dp[i][j]||(dp[i][j-1]&&(s2[j-1]==s3[i+j-1]));
            }
        }
        return dp[l1][l2];
    }
};
// @lc code=end


int main(){
    Solution s;
    string s1="",s2="b",s3="b";
    bool res = s.isInterleave(s1,s2,s3);
    if(res)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}