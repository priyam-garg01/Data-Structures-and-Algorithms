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
    
    void push(int x) {
        s1.push(x);
        size += 1;
    }
    
    int pop() {
        int ans;
       if(!s2.empty()){
        ans = s2.top();
        s2.pop();
       }
       else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
            ans = s2.top();
            s2.pop();
       }
       size -= 1;
       return ans;
    }
    
    int peek() {
         int ans;
       if(!s2.empty()){
        ans = s2.top();
       }
       else{
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
            ans = s2.top();
        }
       }
       return ans;
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