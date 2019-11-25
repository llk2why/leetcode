#include<bits/stdc++.h>
using namespace std;
/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

// @lc code=start
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n=words.size(),p=0,q=1;
        vector<string> res;
        if(n==0)return words;
        while(p<n){
            int sum,ns,nw,lw;
            lw = sum = words[p].size();
            nw=0;
            string s = words[p];

            while(sum<maxWidth){
                if(q<n&&sum+words[q].size()+1<=maxWidth){
                    sum+=words[q].size()+1;
                    lw+=words[q].size();
                    nw++;
                    q++;
                }
                else break;
            }
            ns = maxWidth-lw;

            if(q!=n){
                if(q-p==1)for(int i=0,j=maxWidth-s.size();i<j;i++)
                    s+=' ';
                for(int i=1;i<q-p;i++){
                    for(int i=0;i<ns/nw;i++)s+=' ';
                    if(i<=ns%nw)s+=' ';
                    s+=words[p+i];
                }
            }

            else{
                for(int i=1;i<q-p;i++){
                    s+=' ';
                    s+=words[p+i];
                }
                for(int i=0,j=maxWidth-s.size();i<j;i++)
                    s+=' ';
            }
            res.push_back(s);
            p=q;q++;
        }
        return res;
    }
};
// @lc code=end

int main(){
    Solution s;
    vector<string> words;
    words.push_back("a");
    // words.push_back("This");
    // words.push_back("is");
    // words.push_back("an");
    // words.push_back("example");
    // words.push_back("of");
    // words.push_back("text");
    // words.push_back("justification.");
    // words.push_back("What");
    // words.push_back("must");
    // words.push_back("be");
    // words.push_back("acknowledgment");
    // words.push_back("shall");
    // words.push_back("be");
    vector<string> ans = s.fullJustify(words,16);
    for(auto s:ans){
        cout<<s<<" "<<s.size()<<endl;
    }
}

