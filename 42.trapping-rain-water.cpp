/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */
class Solution {
private:
    priority_queue<int,vector<int>,greater<int> > q;
public:
    void divid_n_conquor(vector<int>& h,int a,int b,int d){
        if(a>=b)return;
        int max=0,p=0;
        if(d==0||d==2)
            for(int i=a;i<=b;i++){
                if(h[i]>=max){
                    max=h[i];
                    p=i;
                }
            }
        if(d==1)
            for(int i=b;i>=a;i--){
                if(h[i]>=max){
                    max=h[i];
                    p=i;
                }
            }
        q.push(p);
        if(d==1||d==0)divid_n_conquor(h,a,p-1,1);
        if(d==2||d==0)divid_n_conquor(h,p+1,b,2);
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> &h=height;
        if(n==0||n==1||n==2)return 0;
        divid_n_conquor(h,0,n-1,0);
        int a,b,m,res=0;
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        m = min(h[a],h[b]);
        for(int i=a;i<n-1;i++){
            if(i==a)continue;
            else if(i==b){
                if(q.empty())break;
                int t=q.top();
                q.pop();
                a=b;
                b=t;
                m = min(h[a],h[b]);
            }
            else{
                res+=(m-h[i]);
            }
        }
        return res;
    }
};

