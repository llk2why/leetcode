/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 */

// @lc code=start
class Solution {
public:
    // int maximalRectangle(vector<vector<char>>& matrix) {
    //     if(matrix.size()==0)return 0;
    //     int m=matrix.size(),n=matrix[0].size();
    //     int h[n],l[n],r[n],res=0;
    //     fill_n(h,n,0);fill_n(l,n,0);fill_n(r,n,n);
    //     for(int i=0;i<m;i++){
    //         int cur_left=0,cur_right=n;
    //         for(int j=0;j<n;j++)
    //             h[j]=matrix[i][j]=='1'?h[j]+1:0;
    //         for(int j=0;j<n;j++){
    //             if(matrix[i][j]=='1')l[j]=max(cur_left,l[j]);
    //             else{l[j]=0;cur_left=j+1;}
    //         }
    //         for(int j=n-1;j>=0;j--){
    //             if(matrix[i][j]=='1')r[j]=min(cur_right,r[j]);
    //             else{r[j]=n;cur_right=j;}
    //         }
    //         for(int j=0;j<n;j++)
    //             if(h[j])res=max(res,h[j]*(r[j]-l[j]));
    //     }
    //     return res;
    // }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())  return 0;
        vector<int> height(matrix[0].size(), 0);
        int maxRect= 0;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < height.size(); ++j) {
                if(matrix[i][j] == '0')    height[j] = 0;
                else    ++height[j];
            }
            maxRect = max(maxRect, largestRectangleArea(height));
            height.pop_back();
        }
        return maxRect;
    }
    int largestRectangleArea(vector<int> &height) {
            int ret = 0;
            height.push_back(0);
            vector<int> index;
            for(int i = 0; i < height.size(); i++) {
                while(index.size() > 0 && height[index.back()] >= height[i]) {
                    int h = height[index.back()];
                    index.pop_back();
                    int sidx = index.size() > 0 ? index.back() : -1;
                    ret = max(ret, h * (i-sidx-1));
                }
                index.push_back(i);
            }
            return ret;
    }
};
// @lc code=end

