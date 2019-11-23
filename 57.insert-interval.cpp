#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 */

// @lc code=start
class Solution {
public:
    int find(vector<vector<int>>& vv,int pos,int n,int e){
        int a=0,b=n-1,mid = (a+b)/2;
        while(a<b&&!(e>=vv[mid][0]&&e<=vv[mid][1])){
            if(vv[mid][0]>e)b=mid-1;
            else if(vv[mid][1]<e)a=mid+1;
            mid = (a+b)/2;
        }
        if(mid==n-1&&vv[mid][1]<e)mid++;
        if(mid<n-1&&e>vv[mid][1]&&e<vv[mid+1][0])mid++;
        return mid;
    }
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0){intervals.push_back(newInterval);return intervals;}
        int li,ri,l,r,cnt=0;
        l = newInterval[0];
        r = newInterval[1];
        li = find(intervals,0,n,l);
        ri = find(intervals,1,n,r);
        cout<<li<<" "<<ri<<endl<<endl;
        intervals.insert(intervals.begin()+li,newInterval);
        for(int i=li+1;i<=ri+1&&i<=n&&intervals[i][0]<=r;i++){
            intervals[li][0]=min(intervals[li][0],intervals[i][0]);
            intervals[li][1]=max(intervals[li][1],intervals[i][1]);
            cnt++;
        }
        intervals.erase(intervals.begin()+li+1,intervals.begin()+li+1+cnt);
        return intervals;
    }
};
// @lc code=end
int main(){
    int a[6][2]={
        {0,10},
        {14,14},
        {15,20},
        {8,10},
        {12,16},
        {11,11}};
    vector<vector<int>> intervals,res;
    for(int i=0;i<3;i++){
        intervals.push_back(vector<int>(a[i],a[i]+2));
    }
    Solution s;
    vector<int> tmp(a[5],a[5]+2);
    res=s.insert(intervals,tmp);
    for(auto &v:res){
        for(auto &e:v){
            cout<<e<<" ";
        }
        cout<<endl;
    }
}

