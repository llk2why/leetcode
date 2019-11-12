/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
class Solution {
public:
    void getNext(const string &s,int *next){
        next[0]=-1;
        int i=0,j=-1;
        while(i<s.size()){
            if(j==-1||s[i]==s[j]){
                i++;
                j++;
                next[i]=j;
            }
            else j=next[j];
        }
    }

    int strStr(string haystack, string needle) {
        if(needle.size()<1)return 0;
        int i=0,j=0;
        int *next = new int[needle.size()];
        getNext(needle,next);
        int l1=haystack.size(),l2=needle.size();
        while(i<l1&&j<l2){
        // while(i<haystack.size()&&j<needle.size()){
            if(j==-1||haystack[i]==needle[j]){
                i++;
                j++;
            }
            else j=next[j];
            cout<<i<<" "<<j<<endl;
        }
        cout<<i<<" "<<j<<endl;
        delete next;
        if(j==needle.size())return i-j;
        return -1;
    }
};

