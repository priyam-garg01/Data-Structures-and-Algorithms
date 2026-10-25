class Solution {
  public:
  
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        int n = arr.size();
        priority_queue<int> pq1;
        
        for(int i = 0; i < k1; i++){
            pq1.push(arr[i]);
        }//k1logk1
        
        for(int i = k1; i < n; i++){
            if(arr[i] < pq1.top()){
                pq1.pop();
                pq1.push(arr[i]);
            }
        }//(n-k1)logk1
        priority_queue<int> pq2;
        
        for(int i = 0; i < k2; i++){
            pq2.push(arr[i]);
        }
        
        for(int i = k2; i < n; i++){
            if(arr[i] < pq2.top()){
                pq2.pop();
                pq2.push(arr[i]);
            }
        }
        
        //O(nlogk1 + nlogk2) = O(nlog(k1*k2)) = O(nlogk)In Big-O notation, dominant terms replace additive combinations of smaller terms
        //O(nlogk1 + nlogk2) = O(nlogk2)
        pq2.pop();//Removed the k2th smallest element
        
        // now run the loop for k2-k1-1 time as 1 element has already been removed from pq2
        int sum = 0;
        while(k2 - k1 - 1){//(k2-k1-1)logk2
            sum += pq2.top();
            pq2.pop();
            k1++;
        }
        
        return sum;
    }
};//T.C. = O(Nlogk2), S.C. = O(k1 + k2 + n)