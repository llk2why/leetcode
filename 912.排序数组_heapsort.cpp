#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {

    inline void build_maxheap(vector<int>& nums,int n){
        for(int i=1;i<n;i++){
            int j=i;
            while(j>0&&nums[(j-1)/2]<nums[j]){
                swap(nums[(j-1)/2],nums[j]);
                j=(j-1)/2;
            }
        }
    }

    inline void update_maxheap(vector<int>& nums,int n){
        int i = 0,p,m;
        p = 2*i+1;
        while((p<n&&nums[i]<nums[p])||(p+1<n&&nums[i]<nums[p+1])){
            m = p;
            if(p+1<n&&nums[p+1]>nums[p])m=p+1;
            swap(nums[i],nums[m]);
            i=m;
            p=2*i+1;
        }
    }

    void heapsort(vector<int>& nums){
        int n = nums.size();
        build_maxheap(nums,n);
        while(n>1){
            swap(nums[0],nums[n-1]);
            n--;
            update_maxheap(nums,n);
        }
    }

public:
    vector<int> sortArray(vector<int>& nums) {
        heapsort(nums);
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