#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=89 lang=cpp
 *
 * [89] Gray Code
 */

// @lc code=start
// class Solution {
// public:
//     vector<int> res;
//     vector<bool> v;
//     bool dfs(int num,int l,int &p,int &n){
//         if(l==p)return true;
//         int b,t;
//         for(int i=0;i<n;i++){
//             int b = 1<<i;
//             if(b&num)t=(~b)&num;
//             else t=b^num;
//             if(!v[t]){
//                 v[t]=true;
//                 res[l]=t;
//                 if(dfs(t,l+1,p,n))return true;
//                 v[t]=false;
//             }
//         }
//         return false;
//     }
//     vector<int> grayCode(int n) {
//         int p = pow(2,n);
//         res.resize(p);v.resize(p);
//         fill_n(v.begin(),p,0);
//         res[0]=0;v[0]=true;
//         dfs(0,1,p,n);
//         return res;
//     }
// };
class Solution {
    
public:
    void tree(bitset<32> &b,vector<int> &res,int n){
        if(n==0)res.push_back(b.to_ulong());
        else{
            tree(b,res,n-1);
            b.flip(n-1);
            tree(b,res,n-1);
        }
    }
    vector<int> grayCode(int n) {
        bitset<32> bits;
        vector<int> res;
        res.reserve(pow(2,n));
        tree(bits,res,n);
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> res = s.grayCode(3);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;
}

