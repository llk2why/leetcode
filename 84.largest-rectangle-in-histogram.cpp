/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> idx;
        int res=0;
        heights.push_back(0);
        idx.push(0);
        for(int i=1,j;i<heights.size();i++){
            while(!idx.empty()&&heights[idx.top()]>heights[i]){
                int h = heights[idx.top()];
                idx.pop();
                j = idx.empty()?-1:idx.top();
                res = max(res,h*(i-j-1));
            }
            idx.push(i);
        }
        return res;
    }
};
// @lc code=end

