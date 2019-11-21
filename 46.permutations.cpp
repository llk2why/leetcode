#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

// @lc code=start
class Solution {
public:
    int l;
    vector<vector<int>> permute(vector<int>& nums) {
        l = nums.size();
        vector<vector<int>> res;
        backtrack(nums,res,0);
        return res;
    }
     void backtrack(vector<int> &nums,vector<vector<int>> &res,int i){
         if(i==l)
             res.push_back(nums);
         for(int j=i;j<l;j++){
             if(i!=j)swap(nums[i],nums[j]);
             backtrack(nums,res,i+1);
             if(i!=j)swap(nums[i],nums[j]);
         }
     }
};

// @lc code=end
int main(){
    Solution s;
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(3);
    vector<vector<int> > res = s.permute(t);
    for(const auto & v:res){
        for(const auto & e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

