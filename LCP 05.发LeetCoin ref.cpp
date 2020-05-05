#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1246 lang=cpp
 *
 * [LCP 05] 发LeetCoin
 */

// @lc code=start
typedef long long ll;
ll mod = 1e9+7;
class Node{
public:
    Node *l,*r;
    int s,e,m;
    ll sum,t;
    bool leaf;
    Node(int s,int e):l(nullptr),r(nullptr),s(s),e(e),m((s+e)/2),sum(0),t(0),leaf(true){}

    Node *left(){
        if(s==e)return nullptr;
        l = l?l:new Node(s,m);
        return l;
    }

    Node *right(){
        if(s==e)return nullptr;
        r = r?r:new Node(m+1,e);
        return r;
    }
    
    void update(int start,int end, int val){
        sum += (ll)val*(end-start+1);
        sum%=mod;
        if(s==start&&e==end){
            t += val;
            return;
        }
        if(leaf){
            // left()->update(s,m,0);
            // right()->update(m+1,e,0);
            leaf=false;
        }
        if(end<=m)left()->update(start,end,val);
        else if(start>=m+1)right()->update(start,end,val);
        else{
            left()->update(start,m,val);
            right()->update(m+1,end,val);
        }
    }

    int query(int start,int end, ll add){
        ll res = 0;
        if(s==start&&e==end){
            res = sum+add*(end-start+1);
            res = res % mod;
            return res;
        }
        add+=t;

        if(leaf){
            res = add*(end-start+1);
            res%=mod;
            return res;
        }

        if(end<=m)return left()->query(start,end,add);
        else if(start>=m+1)return right()->query(start,end,add);
        else return (left()->query(start,m,add)+right()->query(m+1,end,add))%mod;
    }
};

class Solution {
    vector<int> in,out,res;
    void dfs(vector<vector<int>>& sub,int root,int &po){
        in[root]=++po;
        for(auto e:sub[root])dfs(sub,e,po);
        out[root]=po;
    }

    void pre_print(Node *tree,int start,int end){
        if(tree){
            cout<<tree->s<<","<<tree->e<<" "<<tree->sum<<" "<<tree->t<<endl;
            pre_print(tree->left(),tree->s,tree->m);
            pre_print(tree->right(),tree->m+1,tree->e);
        }
    }

public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        vector<vector<int>> sub(n+1);
        in = vector<int>(n+1);
        out = vector<int>(n+1);
        for(auto vec:leadership)sub[vec[0]].push_back(vec[1]);
        int po=-1;
        dfs(sub,1,po);
        Node tree(0,n-1);
        for(auto op:operations){
            if(op[0]==1){
                tree.update(in[op[1]],in[op[1]],op[2]);
            }
            else if(op[0]==2){
                tree.update(in[op[1]],out[op[1]],op[2]);
            }
            else{
                res.push_back(tree.query(in[op[1]],out[op[1]],0));
            }
        }
        pre_print(&tree,0,n-1);
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<vector<int>> leader_ship,operations;
    leader_ship.push_back(vector<int>({1,2}));
    leader_ship.push_back(vector<int>({1,6}));
    leader_ship.push_back(vector<int>({2,3}));
    leader_ship.push_back(vector<int>({2,5}));
    leader_ship.push_back(vector<int>({1,4}));
    operations.push_back(vector<int>{1,1,500});
    operations.push_back(vector<int>{2,2,50});
    operations.push_back(vector<int>{3,1});
    // operations.push_back(vector<int>{2,6,15});
    // operations.push_back(vector<int>{3,1});
    vector<int> res = s.bonus(6,leader_ship,operations);
    for(auto &e:res)cout<<e<<endl;
}