/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
    string countAndSay(int n) {
        string ss[31];
        ss[1]="1";
        ss[2]="11";
        int p=2;
        while(p<n){
            int cnt=0;
            string t="";
            char c='a';
            for(int i=0;i<ss[p].size();i++){
                if(i==ss[p].size()-1){
                    if(ss[p][i]==c){
                        cnt++;
                        t=t+char(cnt+'0')+c;
                    }
                    else t=t+char(cnt+'0')+c+char(1+'0')+ss[p][i];
                }
                else if(ss[p][i]==c){cnt++;}
                else if(c=='a'){cnt=1;}
                else {t=t+char(cnt+'0')+c;cnt=1;}
                c = ss[p][i];
            }
            ss[++p]=t;
        }
        return ss[n];
    }
};

