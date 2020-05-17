/*
 * @lc app=leetcode.cn id=810 lang=cpp
 *
 * [810] 黑板异或游戏
 */

// @lc code=start
class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int res = 0;
        for(int &e:nums)res^=e;
        return res==0||nums.size()%2==0;
    }
};
// @lc code=end

