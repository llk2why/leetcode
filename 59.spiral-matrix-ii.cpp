#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix;
        for(int i=0;i<n;i++)matrix.push_back(vector<int>(n,0));
        int i=0,j=-1;
        if(matrix.size()<1||matrix[0].size()<1)return matrix;
        int u=0,d=n-1,l=0,r=n-1,cnt=1;
        while(true){
            if(j>=r)break;
            while(j<=r){
                j++;
                matrix[i][j]=cnt++;
                if(j==r)break;
            }
            u++;
            if(i>=d)break;
            while(i<=d){
                i++;
                matrix[i][j]=cnt++;
                if(i==d)break;
            }
            r--;
            if(j<=l)break;
            while(j>=l){
                j--;
                matrix[i][j]=cnt++;
                if(j==l)break;
            }
            d--;
            if(i<=u)break;
            while(i>=u){
                i--;
                matrix[i][j]=cnt++;
                if(i==u)break;
            }
            l++;
        }
        return matrix;
    }
};
// @lc code=end
int main(){
    Solution s;
    vector<vector<int>> res = s.generateMatrix(5);
    for(auto v:res){
        for(auto e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
