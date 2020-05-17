/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    int sz;
    bool flag;
    vector<pair<int,int> > s;
    MinStack() {
        sz = 0;
    }
    
    void push(int x) {
        if(!sz)s.push_back({x,x});
        else s.push_back({x,min(x,s[sz-1].second)});
        sz++;
    }
    
    void pop() {
        s.pop_back();
        sz--;
    }
    
    int top() {
        return s[sz-1].first;
    }
    
    int getMin() {
        return s[sz-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

