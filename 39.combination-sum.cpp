/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */
class Solution {
private:
    vector<vector<int> > res;
    int len,t;
public:
    void dfs(vector<int>& c,vector<int> &l,int p,int sum){
        for(int i=p;i<len;i++){
            if(sum+c[i]==t){
                l.push_back(c[i]);
                res.push_back(l);
                l.pop_back();
                break;
            }
            else if(sum+c[i]<t){
                l.push_back(c[i]);
                dfs(c,l,i,sum+c[i]);
                l.pop_back();
            }
            else break;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        len = candidates.size();
        t = target;
        sort(candidates.begin(),candidates.end());
        vector<int> a;
        dfs(candidates,a,0,0);
        return res;
    }
};

