#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    vector<bool> v;
    void dfs(const int &n, int k,int p){
        if(k==0){
            res.push_back(nums);
            return;
        }
        for(int i=p;i<=n;i++){
            if(!v[i]){
                v[i]=true;
                nums.push_back(i);
                dfs(n,k-1,i+1);
                v[i]=false;
                nums.erase(nums.end()-1,nums.end());
            }
        }
    }
    vector<vector<int>> combine(int n, int k) {
        v = vector<bool>(n+2,0);
        dfs(n,k,1);
        return res;
    }
};
// @lc code=end

int main(){
    int n,k;
    n=4;k=2;
    Solution s;
    vector<vector<int>> res = s.combine(n,k);
    for(auto v:res){
        for(auto e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}