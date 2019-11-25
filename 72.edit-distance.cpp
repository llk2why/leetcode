#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size(),row=0;
        if(m==0||n==0)return max(m,n);
        vector<vector<int>> dp;
        for(int i=0;i<=2;i++)dp.push_back(vector<int>(n+1));
        for(int j=0;j<=n;j++)dp[row][j]=j;
        for(int i=1;i<=m;i++){
            row = 1-row;
            dp[row][0]=i;
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[row][j]=min(dp[1-row][j-1],min(dp[row][j-1],dp[1-row][j])+1);
                }
                else dp[row][j]=min(dp[1-row][j-1],min(dp[row][j-1],dp[1-row][j]))+1;
            }
        }
        return dp[row][n];
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<<s.minDistance("horse","ros")<<endl;
}