/*
 * @lc app=leetcode.cn id=679 lang=cpp
 *
 * [679] 24 点游戏
 */

// @lc code=start
class Solution {
    bool solve(vector<double> nums){
        int n = nums.size();
        double eps=1e-6;
        if(n==0)return false;
        if(n==1)return abs(nums[0]-24)<eps;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    vector<double> ls;
                    for(int k=0;k<n;k++)if(k!=i&&k!=j)
                        ls.push_back(nums[k]);
                    for(int k=0;k<4;k++){
                        if(k<2&&j>i)continue;
                        if(k==0)ls.push_back(nums[i]+nums[j]);
                        if(k==1)ls.push_back(nums[i]*nums[j]);
                        if(k==2)ls.push_back(nums[i]-nums[j]);
                        if(k==3){
                            if(nums[j]!=0)
                                ls.push_back(nums[i]/nums[j]);
                            else continue;
                        }
                        if(solve(ls))return true;
                        ls.pop_back();
                    }
                }
            }
        }
        return false;
    }
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> ls(nums.begin(),nums.end());
        return solve(ls);
    }
};
// @lc code=end

