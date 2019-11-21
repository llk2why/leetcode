#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=48 lang=cpp
 *
 * [48] Rotate Image
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(),i,j;
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
                swap(matrix[i][j],matrix[j][i]);
                    
        for(i=0;i<n;i++)
            for(j=0;j<n/2;j++)
                swap(matrix[i][j],matrix[i][n-j-1]);
    }
};
// @lc code=end
int main(){
    vector<vector<int>> m,res;
    for(int i=1;i<=3;i++){
        vector<int> a(3,i);
        m.push_back(a);
    }
    Solution s;
    s.rotate(m);
    for(const auto &v:m){
        for(const auto &e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

