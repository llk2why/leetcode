#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=546 lang=cpp
 *
 * [546] 移除盒子
 */

// @lc code=start

// //Runing time: 448 ms
// class Solution {
//     vector<vector<vector<int>>> m_;
//     int dfs(const vector<int>& boxes,int l,int r,int k){
//         if(l>r)return 0;
//         if(m_[l][r][k]>0)return m_[l][r][k];
//         m_[l][r][k] = dfs(boxes,l,r-1,0)+(k+1)*(k+1);
//         for(int i=l;i<r;i++)
//             if(boxes[i]==boxes[r])
//                 m_[l][r][k]=max(m_[l][r][k],dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));
//         return m_[l][r][k];
//     }
// public:
//     int removeBoxes(vector<int>& boxes) {
//         const int n = boxes.size();
//         m_ = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,0)));
//         return dfs(boxes,0,n-1,0);
//     }
// };

// Runing time: 12 ms
int m[101][101][101];
class Solution{
 private:
    int dfs(const vector<int>& boxes,int l,int r,int k){
        if(l>r)return 0;
        while(l<r&&boxes[r-1]==boxes[r]){--r;++k;}
        if(k==0&&m[l][r][k]>0)return m[l][r][k];
        m[l][r][k] = dfs(boxes,l,r-1,0)+(k+1)*(k+1);
        for(int i=l;i<r;i++)
            if(boxes[i]==boxes[r])
                m[l][r][k]=max(m[l][r][k],dfs(boxes,l,i,k+1)+dfs(boxes,i+1,r-1,0));
        return m[l][r][k];
    }
 public:
    int removeBoxes(vector<int>& boxes){
        memset(m,0,sizeof(m));
        return dfs(boxes,0,boxes.size()-1,0);
    }
};
// @lc code=end

int main(){
    vector<int> a({1,3,2,2,2,3,4,3,1});
    Solution s;
    cout<<s.removeBoxes(a)<<endl;
}