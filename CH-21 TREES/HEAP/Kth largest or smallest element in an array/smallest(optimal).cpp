class Solution {
  public:
  
    void minHeapify(vector<int>& A, int i, int n){
        if(n == 0 || n == 1)return;
        
        int s = i;
        while(s < n){
            int l = 2*i + 1;
            int r = 2*i + 2;
            
            if(l < n && A[l] < A[s])s = l;
            if(r < n && A[r] < A[s])s = r;
        
            if(s != i){
                swap(A[s], A[i]);
                i = s;
                }
            else break;
            }
    }
    void delHeap(vector<int>& A, int n){
        
        swap(A[0], A[n-1]);
        n--;
        
        if(n > 1){
            minHeapify(A, 0, n);
        }
    }
    void buildHeap(vector<int>& A, int n){
        if(n == 0 || n == 1)return;
        
        for(int i = n/2 - 1; i >= 0; i--){
            minHeapify(A, i, n);
        }
    }
    int kthSmallest(vector<int> &arr, int k) {
        int n = arr.size();
        
        //Brute force sort the array and return arr[k - 1] element
        //T.C. = O(NLOGN)
        
        // sort(arr.begin(), arr.end());
        
        // return arr[k-1];
        
        //To convert this O(nlogn) --> O(n)
        /*buildHeap->o(n); first smallest root itself, second smallest either of left or right
        we keep on deleting the element(smallest element till ct = k)  */
        
        buildHeap(arr, n);
        
        int ct = 0;
        while(k-1){
            delHeap(arr, n - ct);
            ct++;
            k--;
        }
        
        return arr[0];

    }
};