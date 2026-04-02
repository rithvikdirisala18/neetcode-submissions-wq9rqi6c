class MinStack {
public:
    stack<int> st;
    stack<int> mins;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        val = min(val, mins.empty()? val: mins.top());
        mins.push(val);
    }
    
    void pop() {
        st.pop();
        mins.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mins.top();
    }
};
