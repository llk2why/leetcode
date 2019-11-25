/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0||matrix[0].size()==0)return;
        int m=matrix.size(),n=matrix[0].size();
        bool row,col;
        row = col = false;
        for(int i=0;i<m;i++){
            if(!matrix[i][0]){
                row=true;
                break;
            }
        }
        for(int j=0;j<n;j++){
            if(!matrix[0][j]){
                col=true;
                break;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][j]){
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(!matrix[i][0]||!matrix[0][j])
                    matrix[i][j]=0;
            }
        }
        if(row)for(int i=0;i<m;i++)matrix[i][0]=0;
        if(col)for(int j=0;j<n;j++)matrix[0][j]=0;
        return;
    }
};
// @lc code=end

