/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

// @lc code=start
class Solution {
public: 
    bool check(vector<string> &chs,int i,int j,int n){
        for(int k=0;k<n;k++){
            if(chs[i][k]=='Q')return false;
            if(chs[k][j]=='Q')return false;
        }
        for(int di=-1;di<=1;di+=2){
            for(int dj=-1;dj<=1;dj+=2){
                int ii=i+di,jj=j+dj;
                while(ii>=0&&ii<n&&jj>=0&&jj<n){
                    if(chs[ii][jj]=='Q')return false;
                    ii += di;
                    jj += dj;
                }
            }
        }
        return true;
    }
    void dfs(int &ans,vector<string> &chs,int i,const int &n){
        if(i==n){
            ans++;
            return;
        }
        else{
            for(int j=0;j<n;j++){
                if(check(chs,i,j,n)){
                    chs[i][j]='Q';
                    dfs(ans,chs,i+1,n);
                    chs[i][j]='.';
                }
            }
        }
        return;
    }
    int totalNQueens(int n) {
        int ans=0;
        string s(n,'.');
        vector<string> chs(n,s);
        dfs(ans,chs,0,n);
        return ans;
    }
};
// @lc code=end

