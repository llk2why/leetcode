#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {

void quicksort(vector<int>& nums,int left,int right){
    // cout<<left<<" "<<right<<endl;
    if(right-left<=0)return;
    if(right-left==1){
        if(nums[left]>=nums[right])swap(nums[left],nums[right]);
        return;
    }
    int pivot = nums[left];
    int l=left,r=right;
    bool inv=true;
    while(l<r){
        if(!inv){
            while(l<r&&nums[l]<=pivot)l++;
            if(l<r){
                nums[r]=nums[l];
                r--;
            }
        }
        else{
            while(l<r&&nums[r]>=pivot)r--;
            if(l<r){
                nums[l]=nums[r];
                l++;
            }
        }
        inv=!inv;
    }
    nums[l]=pivot;
    quicksort(nums,left,l-1);
    quicksort(nums,l+1,right);
}

public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        quicksort(nums,0,n-1);
        return nums;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> nums({-74,48,-20,2,10,-84,-5,-9,11,-24,-91,2,-71,64,63,80,28,-30,-58,-11,-44,-87,-22,54,-74,-10,-55,-28,-46,29,10,50,-72,34,26,25,8,51,13,30,35,-8,50,65,-6,16,-2,21,-78,35,-13,14,23,-3,26,-90,86,25,-56,91,-13,92,-25,37,57,-20,-69,98,95,45,47,29,86,-28,73,-44,-46,65,-84,-96,-24,-12,72,-68,93,57,92,52,-45,-2,85,-63,56,55,12,-85,77,-39});
    s.sortArray(nums);
    cout<<endl;
    for(auto e:nums)cout<<e<<" ";
        cout<<endl;
}