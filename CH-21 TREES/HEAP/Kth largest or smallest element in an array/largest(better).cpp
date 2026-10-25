class Solution {
public:
      
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int ct = 0;

        while(ct != k){
            pq.push(nums[ct]);//O(klogk)
            ct++;
        }
        //A fixed size window is created

        for(int i = k; i < n; i++){//O((n-k)logk)
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
        //T.C. = O(nlogk), S.C. = O(n + k)
    }
};