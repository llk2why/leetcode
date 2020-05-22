/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 */

// @lc code=start
class Solution {
    unordered_map<int,int> mp;
public:
    int superEggDrop(int K, int N) {
        int dp[K+1][N+1];
        memset(dp,0,sizeof(dp));
        for(int m=1;m<=N;m++){
            dp[0][m]=0;
            for(int k=1;k<=K;k++){
                dp[k][m]=dp[k][m-1]+dp[k-1][m-1]+1;
                if(dp[k][m]>=N)return m;
            }
        }
        return N;
    }
};
// @lc code=end

