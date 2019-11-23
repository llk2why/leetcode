#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int i=0,j=-1;
        if(matrix.size()<1||matrix[0].size()<1)return res;
        int u=0,d=matrix.size()-1,l=0,r=matrix[0].size()-1;
        while(true){
            if(j>=r)break;
            while(j<=r){
                j++;
                res.push_back(matrix[i][j]);
                if(j==r)break;
            }
            u++;
            if(i>=d)break;
            while(i<=d){
                i++;
                res.push_back(matrix[i][j]);
                if(i==d)break;
            }
            r--;
            if(j<=l)break;
            while(j>=l){
                j--;
                res.push_back(matrix[i][j]);
                if(j==l)break;
            }
            d--;
            if(i<=u)break;
            while(i>=u){
                i--;
                res.push_back(matrix[i][j]);
                if(i==u)break;
            }
            l++;
        }
        return res;
    }
};
// @lc code=end
int main(){
    int d[5][5]={
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5},
        {1,2,3,4,5}
    };
    vector<vector<int>> a;
    for(int i=0;i<5;i++){
        a.push_back(vector<int>(d[i],d[i]+5));
    }
    Solution s;
    vector<int> res = s.spiralOrder(a);
    for(auto v:res){
        cout<<v<<" ";
    }
    cout<<endl;
    cout<<res.size()<<endl;
}

