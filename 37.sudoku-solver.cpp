/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */
class Solution {
public:
    typedef struct{
        int i,j,p;
    }N;
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<char>>& b=board;
        N q[91];
        bool r[10][10],c[10][10];
        bool block[3][3][10];
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        for(int i=0;i<3;i++)for(int j=0;j<3;j++)for(int k=0;k<10;k++)block[i][j][k]=false;
        int n=0,o=0;
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]!='.')r[i][b[i][j]-'0']=true;
        for(int j=0;j<9;j++)for(int i=0;i<9;i++)if(b[i][j]!='.')c[j][b[i][j]-'0']=true;
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)if(b[i][j]!='.')block[i/3][j/3][b[i][j]-'0']=true;
        for(int i=0;i<9;i++)for(int j=0;j<9;j++)
            if(b[i][j]=='.'){q[n].i=i;q[n].j=j;q[n].p=1;n++;}
        while(o>=0&&o<n){
            int i=q[o].i,j=q[o].j,p=q[o].p,k;
            char ch;
            for(k=p;k<=9;k++){
                ch=k+'0';
                if(!r[i][k]&&!c[j][k]&&!block[i/3][j/3][k]){
                    r[i][k]=true;
                    c[j][k]=true;
                    block[i/3][j/3][k]=true;
                    q[o].p=k;
                    o++;
                    b[i][j]=ch;
                    break;
                }
            }
            if(k>9){
                q[o].p=1;
                while(o>0){
                    o--;
                    i=q[o].i;j=q[o].j;p=q[o].p;
                    b[i][j]='.';
                    ch = p+'0';
                    r[i][p]=false;
                    c[j][p]=false;
                    block[i/3][j/3][p]=false;
                    q[o].p++;
                    if(q[o].p<=9){
                        break;
                    }
                    else{
                        q[o].p = 1;
                    }
                }
            }
        }
    }
};

