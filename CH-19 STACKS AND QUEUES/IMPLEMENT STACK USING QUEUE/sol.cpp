/*
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.*/
class MyStack {
public:
        queue<int> q;//S.C. = O(N)
        int size = 0;
    MyStack() {

    }
    
    void push(int x) {//T.C. = O(N)
        int s = q.size();
        q.push(x);//pushed the element to the last 

//turn the lements at the back while removing from the front
        for(int i = 0; i < s; i++){
            q.push(q.front()); 
            q.pop();
        }
        size = s + 1;
        return;
    }
    
    int pop() {//T.C. = O(1)
        int ans = q.front();
        q.pop();
        size = size-1;
        return ans;
    }
    
    int top() {//T.C. = O(1)
        return q.front();
    }
    
    bool empty() {//T.C. = O(1)
        if(size == 0)return true;
        else return false;
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