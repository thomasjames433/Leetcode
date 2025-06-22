class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        s2.pop();
        
        return x;
    }
    
    int peek() {
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int x=s2.top();
        return x;
        
    }
    
    bool empty() {
        return s1.empty() && s2.empty();
    }
private:
    stack<int>s1,s2;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */


class MyQueue {
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
        if(s1.size()==1)
            top=x;
    }
    
    int pop() {
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int x=s2.top();
        s2.pop();
        if(!s2.empty())
            top=s2.top();
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return x;
    }
    
    int peek() {
        return top;
    }
    
    bool empty() {
        return s1.empty();
    }
private:
    stack<int>s1,s2;
    int top;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
