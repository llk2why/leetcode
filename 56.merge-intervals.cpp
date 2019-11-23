#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[
            &](const vector<int> &a,const vector<int> &b){return a[0]<b[0];});
        vector<vector<int>> res;
        int n = intervals.size();
        if(n<=1)return intervals;
        vector<int> p=intervals[0];
        for(int i=1;i<n;i++){
            if(p[1]>=intervals[i][0])
                p[1]=max(p[1],intervals[i][1]);
            else{
                res.push_back(p);
                p = intervals[i];
            }
        }
        res.push_back(p);
        return res;
    }
};
// @lc code=end


int main(){
    vector<vector<int>> a;
    for(int i=0;i<5;i++){
        int t[] = {5-i,5-i+5};
        a.push_back(vector<int>(t,t+2));
    }
    Solution s;
    vector<vector<int>> intervals = s.merge(a);
    for(auto &v:intervals){
        for(auto &e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}