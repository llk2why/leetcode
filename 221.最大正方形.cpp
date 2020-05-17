#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @lc code=start
class Solution {
    
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n,m;
        n=matrix.size();
        if(n==0)return 0;
        m=matrix[0].size();
        if(m==0)return 0;
        vector<int> dp(m),dp2(m);
        int res=0;
        for(int i=0;i<m;i++)dp[i]=matrix[0][i]-'0',res=max(res,dp[i]);
        for(int i=1;i<n;i++,dp=dp2){
            dp2[0]=matrix[i][0]-'0';
            res=max(dp2[0],res);
            for(int j=1;j<m;j++){
                if(matrix[i][j]-'0')
                    dp2[j]=min(dp2[j-1],min(dp[j],dp[j-1]))+1;
                else dp2[j]=0;
                res = max(res,dp2[j]);
            }
        }
        return res*res;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<char>> mat;
    mat.push_back(vector<char>({'0','1'}));
    cout<<s.maximalSquare(mat)<<endl;
}
