/*
 * @lc app=leetcode.cn id=1035 lang=cpp
 *
 * [1035] 不相交的线
 */

// @lc code=start
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int m,n;
        m=A.size();
        n=B.size();
        if(m==0||n==0)return 0;
        int dp[501][501]={0};
        // for(int i=0;i<=m;i++)dp[i][0]=0;
        // for(int i=1;i<=n;i++)dp[0][i]=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(A[i-1]==B[j-1])
                    dp[i][j]=max(dp[i-1][j-1]+1,dp[i][j]);
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

