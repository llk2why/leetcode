/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N+2,vector<int>(K+2,0x3f3f3f3f));
        for(int j=0;j<=K;j++)dp[0][j]=0;
        for(int j=1;j<=K;j++)dp[1][j]=1;
        for(int i=0;i<=N;i++){
            dp[i][0]=0;
            dp[i][1]=i;
        }
        for(int i=2;i<=N;i++){
            for(int j=2;j<=K;j++){
                for(int k=1;k<=i;k++)
                {
                    dp[i][j] = min(max(dp[k-1][j-1],dp[i-k][j])+1,dp[i][j]);
                }
            }
        }
        return dp[N][K];
    }
};
// @lc code=end

