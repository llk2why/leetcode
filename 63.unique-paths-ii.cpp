/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m,n;
        if(obstacleGrid.size()==0||obstacleGrid[0].size()==0)return 0;
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        if(m==1&&n==1)return obstacleGrid[0][0]?0:1;
        vector<long long> dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1)dp[j]=-1;
                else if(i==0&&j==0)dp[j]=1;
                else if(i==0)dp[j]=dp[j-1];
                else if(j==0)dp[j]=dp[j];
                else{
                    if(dp[j]<=0&&dp[j-1]<=0)
                        dp[j]=-1;
                    else{
                        if(dp[j]>0)dp[j]=dp[j];
                        else dp[j]=0;
                        if(dp[j-1]>0)dp[j]+=dp[j-1];
                    }
                }
                cout<<dp[j]<<" ";
            }
            cout<<endl;
        }
        return dp[n-1]==-1?0:dp[n-1];
    }
};
// @lc code=end

