/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]+nums[j]==target)
                    return vector<int>({j,i});
            }
        }
        return vector<int>();
    }
};
// @lc code=end

