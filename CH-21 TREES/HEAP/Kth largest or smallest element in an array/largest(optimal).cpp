class Solution {
public:
      void maxHeapify(vector<int>& A, int i, int n){
        if(n == 0 || n == 1)return;
        
        int lg = i;
        while(lg < n){
            int l = 2*i + 1;
            int r = 2*i + 2;
            
            if(l < n && A[l] > A[lg])lg = l;
            if(r < n && A[r] > A[lg])lg = r;
        
            if(lg != i){
                swap(A[lg], A[i]);
                i = lg;
                }
            else break;
            }
    }
    void delHeap(vector<int>& A, int n){
        
        swap(A[0], A[n-1]);
        n--;
        
        if(n > 1){
            maxHeapify(A, 0, n);
        }
    }
    void buildHeap(vector<int>& A, int n){
        if(n == 0 || n == 1)return;
        
        for(int i = n/2 - 1; i >= 0; i--){
            maxHeapify(A, i, n);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        
        //Brute force sort the array and return nums[k - 1] element
        //T.C. = O(NLOGN)
        
        // sort(nums.begin(), nums.end());
        
        // return nums[k-1];
        
        //To convert this O(nlogn) --> O(n)
        /*buildHeap->o(n); first smallest root itself, second smallest either of left or right
        we keep on deleting the element(smallest element till ct = k)  */
        
        buildHeap(nums, n);
        
        int ct = 0;
        while(k-1){
            delHeap(nums, n - ct);
            ct++;
            k--;
        }
        
        return nums[0];
    }
};/*T.C. = O(N)//BUILD HEAP + O(KLOGN) --> O(NLOGN){If k == n}
S.C. = O(N)*/