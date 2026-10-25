/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/

class MinStack {
public:
    stack< pair<int, int> > st;//first place stores the new value and the second stores the min value in the stack till that point
    int size = 0;
    MinStack() {
        
    }
    
    void push(int val) {
        if(!st.empty()){
        int prevMin = st.top().second;
        
 //      st.push(val, min(val, prevMin));//push function tales one argument so make represent it in a pair{}
        st.push({val, min(val, prevMin)});
    }
       else st.push({val, val});
       size += 1;
    }
    
    void pop() {
        st.pop();
        size -= 1;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 /*Using a pair to store the min and val simultaneously
T.C. = O(1), S.C. = O2*(N)for storing n pairs*/