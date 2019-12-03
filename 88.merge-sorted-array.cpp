#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start
// class Solution {
// public:
//     void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         if(n==0)return;
//         if(m==0){nums1=nums2;return;}
//         vector<int> t(m+n);
//         int p,q;
//         for(p=q=0;p<m&&q<n;){
//             if(nums1[p]<=nums2[q]){t[p+q]=nums1[p];p++;}
//             else{t[p+q]=nums2[q];q++;}
//         }
//         if(p<m)copy(nums1.begin()+p,nums1.begin()+m,t.end()-(m-p));
//         if(q<n)copy(nums2.begin()+q,nums2.end(),t.end()-(n-q));
//         nums1=t;
//     }
// };
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)return;
        if(m==0){nums1=nums2;return;}
        copy(nums1.begin(),nums1.begin()+m,nums1.end()-m);
        int p,q;
        for(q=0,p=n;p<m+n&&q<n;){
            if(nums1[p]<=nums2[q]){nums1[p+q-n]=nums1[p];p++;}
            else{nums1[p+q-n]=nums2[q];q++;}
        }
        if(q<n)copy(nums2.begin()+q,nums2.end(),nums1.end()-(n-q));
    }
};
// @lc code=end

int main(){
    vector<int> v1(3,3),v2(1,1);
    Solution s;
    v1[0]=0;
    v1[1]=1;
    s.merge(v1,2,v2,1);
    for(auto i:v1){
        cout<<i<<" ";
    }
    cout<<endl;
}

