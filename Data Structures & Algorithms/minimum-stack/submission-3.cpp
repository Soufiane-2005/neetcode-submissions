class MinStack {
private: 
    stack<int> st;
    stack<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min_num;
        if(st.empty()){
            min_num=val;
        }else{
            min_num = min(st2.top(),val);
        }
        st2.push(min_num);
        st.push(val);
    }
    
    void pop() {
        st2.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return st2.top();

    }
};
