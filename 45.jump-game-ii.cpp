#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int i,p,cnt;
        i=p=cnt=0;
        int l = nums.size();
        if(l<=1)return 0;
        while(i+nums[i]<l-1){
            int maxi,ii;
            ii = i;
            maxi=0;
            p=nums[i];
            for(int j=i+1;j<=i+p;j++){
                if(j+nums[j]>maxi){
                    maxi = j+nums[j];
                    ii=j;
                }
            }
            i=ii;
            cnt++;
        }
        if(i!=l-1)cnt++;
        return cnt;
    }
};
// @lc code=end

int main(){
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution s;
    cout<<s.jump(nums)<<endl;
}

