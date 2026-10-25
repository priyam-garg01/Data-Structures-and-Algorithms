class MinStack {
public:
    stack<long long> st;//due to overflow in case of :
    //VALUE = INT_MIN STACK SHOULD BE LONG
    long long mini = INT_MAX;//take a variable for the get min function separately
    //but it stores only one value at a time and if the poped value is min it still points to that 
    //so we use a modified value newVal : 2*value - prevMin = newVal
    long x;//the newVal
    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()){
            mini = value;
            st.push(value);
    }
    else{
        if(value >= mini)st.push(value);
        else{
        st.push(2*(long)value - mini);//mini is prevMin
        mini = value;
        
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        else {
                x = st.top();// x should be defined firt before comparison
            if(x < mini)//it means the min element is about to be deleted
            {
                mini = 2*mini/*(the value last occured as min)*/-x;//x = newVal
                st.pop();
            }
            else{
                x = st.top();
                st.pop();
            }
        }
        
    }
    
    int top() {
        x = st.top();
        if(x < mini){
            return mini;
        }
        else return st.top();
    }
    
    int getMin() {
        return mini;
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
/*
Due to overflow in case of val = int_min we need to use long,
We take a variable and keep storing the min in it for reminder of prevMin, {pop(), getMin operation} we store a modified value in stack each time we get a new min to obtain its previous min 
T.C. = O(1), S.C. = O(N){Stack space} otherwise its O(1)*/