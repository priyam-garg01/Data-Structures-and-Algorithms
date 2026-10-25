/*
Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

void push(int x) Pushes element x to the back of the queue.
int pop() Removes the element from the front of the queue and returns it.
int peek() Returns the element at the front of the queue.
boolean empty() Returns true if the queue is empty, false otherwise.
*/
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    int size = 0;
    /*
    //PROCEDURE 
    1)keep putting the elements in stack 2 from 1st if there are
    2)push the new element and then again put all elements in stack 1
    */
    MyQueue() {
        
    }
    
    void push(int x) {//T.C. = O(2N), S.C. = O(2N)
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.push(x);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        size += 1;
    }
    
    int pop() {
        int ans = s1.top();
        s1.pop();
        size -= 1;
        return ans;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty(){
        if(size == 0)return true;
        else return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
