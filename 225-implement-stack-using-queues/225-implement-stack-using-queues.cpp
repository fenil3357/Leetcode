class MyStack {
public:
    int N;
    queue<int> q1, q2;
    /** Initialize your data structure here. */
    MyStack() {
         N = 0;
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q2.push(x);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = q1.front();
        q1.pop();
        N--;
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return q1.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        if(N!=0) return false;
        return true;
    }
};
