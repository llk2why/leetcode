/*
 * @lc app=leetcode.cn id=913 lang=cpp
 *
 * [913] 猫和老鼠
 */

// @lc code=start
class Solution {
    vector<vector<int>> parents(vector<vector<int>>& graph,int m,int c,int t){
        vector<vector<int>> ret;
        if(t==2)
            for(int m2:graph[m])
                ret.push_back({m2,c,3-t});
        else
            for(int c2:graph[c])if(c2!=0)
                ret.push_back({m,c2,3-t});
        return ret;
    }

public:
    int color[50][50][3];
    int degree[50][50][3];
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        const int DRAW=0,MOUSE=1,CAT=2;
        
        for(int m=0;m<n;m++){
            for(int c=0;c<n;c++){
                degree[m][c][1] = graph[m].size();
                degree[m][c][2] = graph[c].size();
                for(int &x:graph[c])if(x==0){
                    degree[m][c][2]--;
                    break;
                }
            }
        }

        queue<vector<int>> q;
        for(int c=0;c<n;c++){
            for(int t=1;t<=2;t++){
                color[0][c][t]=MOUSE;
                q.push({0,c,t,MOUSE});
                if(c>0){
                    color[c][c][t]=CAT;
                    q.push({c,c,t,CAT});
                }
            }
        }

        while(!q.empty()){
            vector<int> tmp = q.front();
            int m=tmp[0],c=tmp[1],t=tmp[2],status=tmp[3];
            q.pop();
            for(auto parent:parents(graph,m,c,t)){
                int m2=parent[0];
                int c2=parent[1];
                int t2=parent[2];
                if(color[m2][c2][t2]!=DRAW)continue;
                if(status==t2){
                    color[m2][c2][t2]=status;
                    q.push({m2,c2,t2,status});
                }
                else{
                    degree[m2][c2][t2]--;
                    if(degree[m2][c2][t2]==0){
                        color[m2][c2][t2]=3-t2;
                        q.push({m2,c2,t2,3-t2});
                    }
                }
            }
        }
        return color[1][2][1];
    }
};
// @lc code=end

