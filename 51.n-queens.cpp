#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
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
    void dfs(vector<vector<string>> &res,vector<string> &chs,int i,const int &n){
        if(i==n){
            res.push_back(chs);
            return;
        }
        else{
            for(int j=0;j<n;j++){
                // cout<<"x"<<endl;
                if(check(chs,i,j,n)){
                    chs[i][j]='Q';
                    dfs(res,chs,i+1,n);
                    chs[i][j]='.';
                }
            }
        }
        // cout<<"x"<<endl;
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        string s(n,'.');
        vector<string> chs(n,s);
        dfs(res,chs,0,n);
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<string>> ans=s.solveNQueens(5);
    for(const auto &v:ans){
        for(const auto &s:v){
            cout<<s<<endl;
        }
        cout<<endl;
    }
}

