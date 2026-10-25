class StockSpanner {
public:
stack <pair <int,int> > st;
int i = 0;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int count = 0;
        //we don't need to run an entire loop of the elements again and again, we could just store the previous greater element along with its index to find out the number of days
        while(!st.empty() && st.top().first <= price)st.pop();
        int topId = !st.empty()?st.top().second:-1;
        st.push({price, i});
        int ans = i - topId;
        i++;
    return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
/*//we don't need to run an entire loop of the elements again and again, we could just store the previous greater element along with its index to find out the number of days
T.C. = O(2N){for all the total number of next calls}{like in prev greater element}, S.C. =O(N)
for individual it will be T.C. = O(k) k is ans*/