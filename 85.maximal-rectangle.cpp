/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)return 0;
        int m=matrix.size(),n=matrix[0].size();
        int h[n],l[n],r[n],res=0;
        fill_n(h,n,0);fill_n(l,n,0);fill_n(r,n,n);
        for(int i=0;i<m;i++){
            int cur_left=0,cur_right=n;
            for(int j=0;j<n;j++)
                h[j]=matrix[i][j]=='1'?h[j]+1:0;
            for(int j=0;j<n;j++){
                if(matrix[i][j]=='1')l[j]=max(cur_left,l[j]);
                else{l[j]=0;cur_left=j+1;}
            }
            for(int j=n-1;j>=0;j--){
                if(matrix[i][j]=='1')r[j]=min(cur_right,r[j]);
                else{r[j]=n;cur_right=j;}
            }
            for(int j=0;j<n;j++)
                if(h[j])res=max(res,h[j]*(r[j]-l[j]));
        }
        return res;
    }
};
// @lc code=end

