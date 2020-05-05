#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int> > mp;
        for(int i=0;i<nums.size();i++)mp[nums[i]].push_back(i);
        for(int i=0;i<nums.size();i++){
            int a=nums[i],b=target-a;
            if(a==b){
                if(mp[a].size()>1)return vector<int>({mp[a][0],mp[a][1]});
            }
            else if(mp.find(b)!=mp.end()) 
                return vector<int>({mp[a][0],mp[b][0]});
        }
        return vector<int>();
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums({2,5,5,11});
    vector<int> res = s.twoSum(nums,10);
    for(auto e:res)cout<<e<<" ";
    cout<<endl;
}

