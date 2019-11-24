#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        k=k-1;
        vector<int> mid,num;
        for(int i=1;i<=n;i++)num.push_back(i);
        for(int i=2;i<n;i++){
            mid.push_back(k%i);
            k/=i;
        }
        mid.push_back(k);
        reverse(mid.begin(),mid.end());
        for(auto &j:mid){
            res += num[j]+'0';
            num.erase(num.begin()+j,num.begin()+j+1);
        }
        if(n!=1)res += num[0]+'0';
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    string res = s.getPermutation(5,5);
    cout<<res<<endl;
}

