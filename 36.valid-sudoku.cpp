/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                char c=board[i][j];
                if(c!='.'){
                    if(s.find(c)==s.end()){
                        s.insert(c);
                    }
                    else return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            set<char> s;
            for(int j=0;j<9;j++){
                char c=board[j][i];
                if(c!='.'){
                    if(s.find(c)==s.end()){
                        s.insert(c);
                    }
                    else return false;
                }
            }
        }
        set<char> ss[3][3];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                set<char> &s=ss[i/3][j/3];
                if(c!='.'){
                    if(s.find(c)==s.end()){
                        s.insert(c);
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};

