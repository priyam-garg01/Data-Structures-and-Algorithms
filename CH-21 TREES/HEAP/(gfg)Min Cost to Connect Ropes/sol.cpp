/*Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. 
The cost to connect two ropes is the sum of their lengths. Return the minimum possible cost.

Examples:

Input: arr[] = [4, 3, 2, 6]
Output: 29
Explanation: First connect 2 and 3 to get [4, 5, 6] with a cost of 5, then connect 4 and 5 to get [9, 6] with a cost of 9, and finally connect 9 and 6 to get one rope with a cost of 15, giving a total minimum cost of 29. Any other order, such as connecting 4 and 6 first, results in a higher total cost of 38.
Input: arr[] = [4, 2, 7, 6, 9]
Output: 62 
Explanation: First, connect ropes 4 and 2, which makes the array [6, 7, 6, 9]. Cost of this operation 4 + 2 = 6. Next, add ropes 6 and 6, which results in [12, 7, 9]. Cost of this operation 6 + 6 = 12. Then, add 7 and 9, which makes the array [12,16]. Cost of this operation 7 + 9 = 16. And finally, add these two which gives [28]. Hence, the total cost is 6 + 12 + 16 + 28 = 62.
Input: arr[] = [10]
Output: 0
Explanation: Since there is only one rope, no connections are needed, so the cost is 0.
Constraints:

1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 104*/
class Solution {
  public:
    void maxHeapify(vector<int>& A, int i, int n){
        int l = i;
        int lf = 2*i + 1;
        int rt = 2*i + 2;
        
        if(lf < n && A[lf] > A[l])l = lf;
        if(rt < n && A[rt] > A[l])l = rt;
        
        if(l != i){
            swap(A[l], A[i]);
            maxHeapify(A, l, n);
        }
    }
    void buildMaxHeap(vector<int>& A, int n){
        if(n == 0 || n == 1)return;
        
        for(int i = n/2 - 1; i >= 0; i--){
            maxHeapify(A, i, n);
        }
    }
    void heapSort(vector<int> &A, int n){
        if(n == 0 || n ==1)return;
        
        buildMaxHeap(A, n);
        
        for(int i = n - 1; i > 0; i--){
            swap(A[0], A[i]);
            maxHeapify(A, 0, i);
        }
        
    }
    int minCost(vector<int>& arr) {
        /*False thinking
        //Cost minimum tab hogi jab do smallest ropes ko connect kiya jaaye
        //Make maxHeap and apply heapSort
        int n = arr.size();
        if(n == 0 || n == 1)return 0;
        
        heapSort(arr, n);
        
        int cost = 0;
        int sum = arr[0];
        for(int i = 1; i < n; i++){
            sum += arr[i];
            cost += sum;
        }
        
        */
        
        /*We don't have to take the connected rope to connect with the incoming rope
        //But the 2 ropes with min length at that time
        That is dynamic updation and storing*/
        
        
        /*For this we need a priority queue with min priority
        that is we create a min heap*/
        int n = arr.size();
        if(n == 0 || n == 1)return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 0; i < n; i++){
            pq.push(arr[i]);
        }
        
        int cost = 0;
        while(pq.size() > 1){
            int r1 = pq.top();
            pq.pop();
            // if(pq.empty())break;
            int r2 = pq.top();
            pq.pop();
            pq.push(r1 + r2);
            cost += r1 + r2;
        }
    
        return cost;
    }
};//T.C. = O(NLOGN), S.C. = O(2N)