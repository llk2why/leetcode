#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1246 lang=cpp
 *
 * [1246] 删除回文子数组
 */

// @lc code=start
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        int dp[101][101];
        int n = arr.size();
        memset(dp,0x3f,sizeof(dp));
        for(int i=1;i<=n;i++)dp[i][i]=1;
        for(int i=1;i<n;i++)dp[i][i+1]=(arr[i-1]==arr[i]?1:2);
        for(int l=3;l<=n;l++){
            for(int i=1;i+l-1<=n;i++){
                int j = i+l-1;
                // dp[i][j] = min(dp[i][j],dp[i+1][j]+1);
                // dp[i][j] = min(dp[i][j],dp[i][j-1]+1);
                for(int k=i;k<j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
                if(arr[i-1]==arr[j-1]){
                    dp[i][j]=min(dp[i][j],dp[i+1][j-1]);
                }
            }
        }
        return dp[1][n];
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> a = vector<int>({1,4,1,1,2,3,2,1});
    cout<<s.minimumMoves(a)<<endl;
}