class Solution {
  public:
  
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();

               priority_queue<int> pq;
               int ct = 0;

               while(ct != k){
                   pq.push(arr[ct]);
                   ct++;
               }
               //A fixed size window is created

               for(int i = k; i < n; i++){
                   if(arr[i] < pq.top()){
                       pq.pop();
                       pq.push(arr[i]);
                   }
               }
               return pq.top();
    }
};