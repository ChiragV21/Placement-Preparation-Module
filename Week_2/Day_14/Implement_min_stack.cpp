class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> mi;
        
    void push(int x) {
        st.push(x);
        if(mi.empty() || x<=mi.top())
        {
            mi.push(x);
        }
        
        
    }
    
    void pop() {
        
        if(st.top() == mi.top())
        {
            mi.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mi.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */