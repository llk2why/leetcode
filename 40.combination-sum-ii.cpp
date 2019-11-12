/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */
class Solution {
private:
    set<vector<int> > res;
    int len,t;
public:
    void dfs(vector<int>& c,vector<int> &l,int p,int sum){
        for(int i=p+1;i<len;i++){
            if(sum+c[i]==t){
                l.push_back(c[i]);
                res.insert(l);
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        len = candidates.size();
        vector<vector<int> > ret;
        t = target;
        sort(candidates.begin(),candidates.end());
        vector<int> a;
        dfs(candidates,a,-1,0);
        for(auto it=res.begin();it!=res.end();it++){
            ret.push_back(*it);
        }
        return ret;
    }
};

