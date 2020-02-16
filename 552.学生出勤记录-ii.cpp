#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=552 lang=cpp
 *
 * [552] 学生出勤记录 II
 */

// @lc code=start
class Solution {
public:
    int checkRecord(int n) {
        unsigned m = 1e9+7,res=0,cur,ncur;
        unsigned dp[2][2][4]={{0}};
        dp[0][0][0]=1;
        cur = 1;
        for(int i=1;i<=n;i++,cur=!cur){
            ncur = !cur;
            dp[cur][0][0] = (dp[ncur][0][0]+dp[ncur][0][1]+dp[ncur][0][3])%m;
            dp[cur][0][1] = dp[ncur][0][0];
            dp[cur][0][3] = dp[ncur][0][1];
            dp[cur][1][0] = (dp[ncur][1][0]+dp[ncur][1][1]+dp[ncur][1][2]+dp[ncur][1][3])%m;
            dp[cur][1][1] = (dp[ncur][1][0]+dp[ncur][1][2])%m;
            dp[cur][1][2] = (dp[ncur][0][0]+dp[ncur][0][1]+dp[ncur][0][3])%m;
            dp[cur][1][3] = dp[ncur][1][1];
        }

        for(int i=0;i<2;i++)for(int j=0;j<4;j++)
            res=(res+dp[!cur][i][j])%m;
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<<s.checkRecord(3)<<endl;
}