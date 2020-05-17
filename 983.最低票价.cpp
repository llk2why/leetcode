/*
 * @lc app=leetcode.cn id=983 lang=cpp
 *
 * [983] 最低票价
 */

// @lc code=start
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = sizeof(days);
        if(n==1)return min(costs[0],min(costs[1],costs[2]));
        int dp[366],p=1;
        memset(dp,0x3f,sizeof(dp));
        dp[0]=0;
        for(auto e:days){
            while(p<e){
                dp[p]=dp[p-1];
                p++;
            }
            dp[e]=min(dp[e],dp[e-1]+costs[0]);
            if(e<=7)dp[e]=min(dp[e],costs[1]);
            else dp[e]=min(dp[e],dp[e-7]+costs[1]);
            if(e<=30)dp[e]=min(dp[e],costs[2]);
            else dp[e]=min(dp[e],dp[e-30]+costs[2]);
            p++;
        }
        // for(int i=1;i<=31;i++)cout<<dp[i]<<" ";
        // cout<<endl;
        return dp[days[days.size()-1]];
    }
};
// @lc code=end

