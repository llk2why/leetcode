#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=903 lang=cpp
 *
 * [903] DI 序列的有效排列
 */

// @lc code=start
class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length(), mod = 1e9 + 7;
        vector<int> dp(n+1,1),dp2(n+1,0);
        for(int i=0;i<n;i++,dp=dp2){
            if(S[i]=='I')
                for(int j=0,cur=0;j<n-i;j++)
                    dp2[j]=cur=(cur+dp[j])%mod;
            else
                for(int j=n-i-1,cur=0;j>=0;j--)
                    dp2[j]=cur=(cur+dp[j+1])%mod;
        }
        return dp[0];
    }
};
// @lc code=end

int main(){
    string s = "DID";
    Solution so;
    cout<<so.numPermsDISequence(s)<<endl;;
}

