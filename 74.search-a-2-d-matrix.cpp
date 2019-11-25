/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0||matrix[0].size()==0)return false;
        int m=matrix.size(),n=matrix[0].size();
        int a,b,mid,it;
        a=0;b=m-1;
        while(a<=b){
            mid=(a+b)/2;
            if(matrix[mid][0]<=target&&matrix[mid][n-1]>=target)
                break;
            else if(matrix[mid][0]>target)b=mid-1;
            else a=mid+1;
        }
        if(matrix[mid][0]>target||matrix[mid][n-1]<target)
            return false;
        it = mid;
        a=0;b=n-1;
        while(a<=b){
            mid=(a+b)/2;
            if(matrix[it][mid]==target)
                return true;
            else if(matrix[it][mid]>target)b=mid-1;
            else a=mid+1;
        }
        return false;
    }
};
// @lc code=end

