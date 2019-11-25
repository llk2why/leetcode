/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start
class Solution {
public:
    // good algorithm, like flag color problem.
    void sortColors(vector<int>& nums) {
        int _1fidx = 0, _2fidx = 0;        
        
        for(int i = 0; i < nums.size(); i++){            
            if(nums[i] == 0){
                nums[i] = 2;
                nums[_2fidx] = 1;
                nums[_1fidx] = 0;
                _1fidx++;
                _2fidx++;                    
            }            
            else if(nums[i] == 1){
                nums[i] = 2;
                nums[_2fidx] = 1;
                _2fidx++;
            }            
        } 
    }
};
// @lc code=end

