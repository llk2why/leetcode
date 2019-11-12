/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res,gap,tr,tg;
        gap = 0x3f3f3f3f;
        vector<int>::iterator i,j,k;
        for(i = nums.begin();i!=nums.end()-2;i++){
            j = i+1;
            k = nums.end()-1;
            while(j<k){
                tr = *i+*j+*k;
                tg = abs(tr-target);
                if(tg<gap){
                    gap = tg;
                    res = tr;
                }
                if(tr-target==0)return target;
                else if (tr-target>0)k--;
                else j++;
            }
        }
        return res;
    }
};
