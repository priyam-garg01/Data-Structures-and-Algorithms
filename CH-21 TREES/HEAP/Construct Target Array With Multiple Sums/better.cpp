class Solution {
public:
    bool isPossible(vector<int>& target) {
        //We are given an arr consisting of n 1's we need to sum the n 1's consecutively such that we create the target array
        int n = target.size();
        if(n == 1)return target[0] == 1;

        //We use reverse eng i.e. reduce target to arr via linear search

        priority_queue<long long> pq;
        long long total_sum = 0;

        for(int i = 0; i < n; i++){
            pq.push(target[i]);
            total_sum += target[i];
        }

        long long maxElem, rem_sum, prev_val;
        while(pq.top() != 1){//O(SlogN)
            maxElem = pq.top();
            pq.pop();

            rem_sum = total_sum - maxElem;
    if(rem_sum <= 0 || rem_sum >= maxElem)return false;

            prev_val = maxElem - rem_sum;
    if(prev_val <= 0)return false;
    
            total_sum = rem_sum + prev_val;
            pq.push(prev_val);
        }

        return true;
    }
};/*TLE*/