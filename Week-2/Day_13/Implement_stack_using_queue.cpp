class MyStack {
public:
    queue<int>s1;
    MyStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        int p=s1.size(),i=0;
        
        while(i<(p-1)){
            s1.push(s1.front());
            s1.pop();
            i++;
        }
       
    }
    
    int pop() {
        int y=s1.front();
        s1.pop();
        return y;
    }
    
    int top() {
       return s1.front();
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */