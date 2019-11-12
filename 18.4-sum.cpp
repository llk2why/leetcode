/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        set<vector<int> > s;
        vector<vector<int> > ret;
        long long tr;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                for(int k=j+1,l=nums.size()-1;k<l;){
                    tr = nums[i]+nums[j]+nums[k]+nums[l];
                    if(tr==target){
                        s.insert(vector<int> {nums[i],nums[j],nums[k],nums[l]});
                        k++;
                        l--;
                    }
                    else if (tr<target)k++;
                    else l--;
                }
            }
        }
        for (auto it = s.begin();it!=s.end();it++)
            ret.push_back(*it);
        return ret;
    } 
};

