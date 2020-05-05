#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=1246 lang=cpp
 *
 * [LCP 05] 发LeetCoin
 */

// @lc code=start

typedef long long ll;
const ll mod = 1e9+7;

class Node{
public:
    int s,e,m;
    ll sum,quo;
    Node *l,*r;
    bool leaf;
    Node(int s,int e):s(s),e(e),m((s+e)/2),l(nullptr),r(nullptr),sum(0),quo(0),leaf(true){}

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

    void update(int start,int end,int val){
        sum += (end-start+1)*(ll)val;
        sum%=mod;
        if(s==start&&e==end){
            quo += val;
            quo%=mod;
            return;
        }
        
        leaf = false;

        if(end<=m)left()->update(start,end,val);
        else if(m+1<=start)right()->update(start,end,val);
        else{
            left()->update(start,m,val);
            right()->update(m+1,end,val);
        }
    }

    int query(int start,int end, ll add){
        ll res = 0;
        if(s==start&&e==end){
            res = sum+add*(end-start+1);
            res %= mod;
            return res;
        }

        add += quo;
        add %= mod;

        if(leaf){
            res = add*(end-start+1);
            res %= mod;
            return res;
        }

        if(end<=m)return left()->query(start,end,add);
        else if(m+1<=start)return right()->query(start,end,add);
        else return (left()->query(start,m,add)+right()->query(m+1,end,add))%mod;
    }
    
};

class Solution {
    vector<vector<int> > sub;
    vector<int> in,out,res;

    void pre_order(int root,int &index){
        in[root] = ++index;
        for(auto &e:sub[root])pre_order(e,index);
        out[root] = index;
    }

public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        in = vector<int>(n+1);
        out = vector<int>(n+1);
        sub = vector<vector<int>>(n+1,vector<int>());
        for(auto &vec:leadership)sub[vec[0]].push_back(vec[1]);
        int index = -1;
        pre_order(1,index);
        Node tree(0,n-1);

        for(auto &op:operations){
            if(op[0]==1)tree.update(in[op[1]],in[op[1]],op[2]);
            else if(op[0]==2)tree.update(in[op[1]],out[op[1]],op[2]);
            else res.push_back(tree.query(in[op[1]],out[op[1]],0));
        }

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
    operations.push_back(vector<int>{2,6,15});
    operations.push_back(vector<int>{3,1});
    vector<int> res = s.bonus(6,leader_ship,operations);
    for(auto &e:res)cout<<e<<endl;
}