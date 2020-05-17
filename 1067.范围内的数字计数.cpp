#include <bits/stdc++.h>
using namespace std;

class Solution {

    int count(int n,int d){
        int cnt=0;
        for(int i=1,k=n,h=n/10;k!=0;i*=10,k=n/i,h=k/10){
            if(d==0){
                if(h!=0)h--;
                else break;
            }
            cnt+=h*i;
            int cur = k%10;
            if(cur>d)cnt+=i;
            else if(cur==d){
                cnt += n-i*k+1;
            }
        }
        return cnt;
    }

public:
    int digitsCount(int d, int low, int high) {
        return count(high,d)-count(low-1,d);
    }
};

int main(){
    Solution s;
    cout<<s.digitsCount(1,1,100)<<endl;
}