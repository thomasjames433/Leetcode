class MyStack {

private:
    queue<int>q1,q2;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        if(q2.empty())
            q2.push(x);
        else{
            q1.push(q2.front());
            q2.pop();
            q2.push(x);

        }
    }
    
    int pop() {
        int x=q2.front();
        q2.pop();
        while(q1.size()>1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.swap(q2);
        return x;
    }
    
    int top() {
        return q2.front();
    }
    
    bool empty() {
        return !q2.size();
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