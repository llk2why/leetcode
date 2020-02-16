#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 */

// @lc code=start
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        if(!n)return 0;
        stack<int> s;
        s.push(arr[0]);
        for(int i=1;i<n;i++){
            if(arr[i]>=s.top())s.push(arr[i]);
            else{
                int h=s.top();
                while(!s.empty()&&s.top()>arr[i])s.pop();
                s.push(h);
            }
        }
        return s.size();
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<int> arr({2,1,3,4,4});
    // vector<int> arr({4,2,2,1,1});
    // vector<int> arr({5,1,1,8,1,6,5,9,7,8});
    cout<<s.maxChunksToSorted(arr)<<endl;;
}

