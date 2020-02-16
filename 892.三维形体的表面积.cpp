/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 */

// @lc code=start
class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0,xx,yy;
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans += 2;
                    for(int k=0;k<4;k++){
                        xx = i+dx[k];
                        yy = j+dy[k];
                        if(xx<0||xx>=n||yy<0||yy>=n)
                            ans += grid[i][j];
                        else 
                            ans += max(0,grid[i][j]-grid[xx][yy]);
                        
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

