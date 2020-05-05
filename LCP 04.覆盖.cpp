#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int from[101],mat[101][101];
    bool v[101],unvisible[101];

    int match(const int &n,const int &m,int idx){
        for(int i=0;i<n*m;i++){
            int r=i/m,c=i%m;
            if(unvisible[i])continue;
            if((r+c)&1)continue;
            if(!mat[idx][i])continue;
            if(!v[i]){
                v[i]=true;
                if(from[i]<0||match(n,m,from[i])){
                    from[i]=idx;
                    return 1;
                }
            }
        }
        return 0;
    }

    int hungary(const int &n,const int &m){
        int match_size=0;
        memset(from,-1,sizeof(from));
        for(int i=0;i<n*m;i++){
            int r=i/m,c=i%m;
            if(unvisible[i])continue;
            if(!((r+c)&1))continue;
            memset(v,0,sizeof(v));
            match_size+=match(n,m,i);
        }
        return match_size;
    }

public:
    int domino(int n, int m, vector<vector<int>>& broken) {
        memset(mat,0,sizeof(mat));
        memset(unvisible,0,sizeof(unvisible));
        for(auto &vec:broken){
            int id = vec[0]*m+vec[1];
            unvisible[id]=true;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int id1,id2,id3;
                id1 = i*m+j;
                id2 = (i+1)*m+j;
                id3 = i*m+j+1;
                if(unvisible[id1])continue;
                if(i+1<n&&!unvisible[id2])mat[id1][id2]=mat[id2][id1]=true;
                if(j+1<m&&!unvisible[id3])mat[id1][id3]=mat[id3][id1]=true;
            }
        }
        return hungary(n,m);
    }
};

int main(){
    Solution s;
    vector<vector<int>> broken;
    broken.push_back(vector<int>({1,0}));
    broken.push_back(vector<int>({1,1}));
    int res = s.domino(2,3,broken);
    cout<<res<<endl;
}