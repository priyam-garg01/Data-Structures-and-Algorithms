class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1)return nums;
        vector<int> ans;
        // stack<int> st;
        //Monotonic decreasing stack stores only larger elements
        
        deque<int> dq;
        for(int i = 0; i < n; i++){

    while(!dq.empty() && nums[i] > nums[dq.back()])dq.pop_back();
        while(!dq.empty() && (i - dq.front() >= k)){//The only k elements in the window may be present in deque
            dq.pop_front();
        }
           dq.push_back(i);
        if(i >= k-1){
            ans.push_back(nums[dq.front()]); 
        }
    }
        return ans;
    }
};/*
//Monotonic decreasing stack stores only larger elements
 we clearly need to check the maximum out of the consecutive k elements but also keep updating those three window elements
    For this we use a DEQUE
T.C. = O(N) + O(N){FOR PUSHING AND POPPING} = O(2N)
S.C. = O(N - K){FOR THE ANS} + O(K) FOR THE DEQUE ACTING LIKE A WINDOW
S.C. = O(N)*/