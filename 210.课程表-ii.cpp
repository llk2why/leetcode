/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start

class Solution {
private:
    vector<vector<int>> to;
    vector<int> v;
    vector<int> res;
    bool flag = false;

    void dfs(int i){
        v[i]=1;
        for(int e:to[i]){
            if(v[e]==0){
                dfs(e);
                if(flag)return;
            }
            else if (v[e]==1){
                flag=true;
                return;
            }
        }
        v[i]=2;
        res.push_back(i);
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int &n = numCourses;
        to.resize(n);
        v.resize(n);

        for(auto &vec:prerequisites) to[vec[1]].push_back(vec[0]);
        for(int i=0;i<n;i++)if(!v[i])dfs(i);
        if(flag)return {};
        reverse(res.begin(),res.end());
        return res;
    }
};
// @lc code=end

