#include<bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int m,n,l;
    vector<int> dx,dy;
    bool dfs(vector<vector<char>>& board,string &s,int d,int x,int y){
        if(d==l)return true;
        if(board[x][y]=='\0')return false;
        char c = board[x][y];
        if(board[x][y]!=s[d])return false;
        else if(d+1==l)return true;
        board[x][y]='\0';
        for(int i=0,xx,yy;i<4;i++){
            xx = x+dx[i];
            yy = y+dy[i];
            if(xx<0||xx>=m||yy<0||yy>=n)continue;
            if(dfs(board,s,d+1,xx,yy))return true;
        }
        board[x][y]=c;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)return true;
        if(board.size()==0||board[0].size()==0)return false;
        m=board.size();n=board[0].size();l=word.size();
        int ddx[4]={0,1,0,-1},ddy[4]={1,0,-1,0};
        dx = vector<int>(ddx,ddx+4);
        dy = vector<int>(ddy,ddy+4);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board,word,0,i,j))return true;
            }
        }
        return false;
    }
};
// @lc code=end

int main(){
    vector<vector<char>> b;
    int m=1,n=2;
    for(int i=0;i<1;i++)b.push_back(vector<char>());
    string s = "ab",word="ba";
    for(int i=0,k=0;i<m;i++){
        for(int j=0;j<n;j++,k++){
            b[i].push_back(s[k]);
        }
    }
    Solution so;
    if(so.exist(b,word))cout<<"true"<<endl;
    else cout<<"false"<<endl;
    return 0;
}

