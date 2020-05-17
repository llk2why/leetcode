#include <bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode.cn id=365 lang=cpp
 *
 * [365] 水壶问题
 */

// @lc code=start

class Solution {
    inline int gcd(int a,int b) {
        while(b^=a^=b^=a%=b);
        return a;
    }
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x+y<z)return false;
        if(x==0||y==0)return z==0||x+y==z;
        return z%gcd(x,y)==0;
    }
};
// @lc code=end

int main(){
    Solution s;
    cout<<s.canMeasureWater(3,5,4)<<endl;
}