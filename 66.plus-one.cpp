/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int p=n-1;
        digits[p]+=1;
        while(p!=0&&digits[p]>=10){
            digits[p]-=10;
            digits[p-1]++;
            p--;
        }
        if(digits[p]>=10){
            digits[p]-=10;
            digits.insert(digits.begin(),1);
        }
        return digits;
    }
};
// @lc code=end

