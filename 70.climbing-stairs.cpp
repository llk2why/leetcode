#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=70 lang=cpp
 *
 * [70] Climbing Stairs
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int a,b,c;
        a=b=c=1;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};
// @lc code=end
int main(){
    int n=5;
    Solution s;
    cout<<s.climbStairs(n)<<endl;;
}

