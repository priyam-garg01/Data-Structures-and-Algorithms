class Solution {
  public:
    void minHeapify(vector<int>& arr, int i, int n){
        if(n == 0 || n == 1)return;
        int s = i;
        
        int left = 2*i + 1;
        int right = 2*i + 2;

        while(s < n){

            if(left < n && arr[s] > arr[left])s = left;
            if(right < n && arr[s] > arr[right])s = right;

            if(s != i){
                swap(arr[i], arr[s]);
                i = s;
                left = 2*i + 1;
                right = 2*i + 2;
            }
            else break;
        }
    }
    void deleteHeap(vector<int>& arr, int &n){
        if(n == 0)return;

        swap(arr[0], arr[n-1]);
        n--;

        minHeapify(arr, 0, n);
    }
    void buildMinHeap(vector<int>& arr, int n){
        if(n == 0 || n == 1)return;

        for(int i = n/2-1; i >= 0; i--){
            minHeapify(arr, i, n);
        }
    }
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        //Build minHeap
        vector<int> arr;
        for(int i = 0; i < n; i++){//O(N^2(logk))
            for(int j = 0; j < n; j++){
                arr.push_back(matrix[i][j]);
            }
        }
        int size = n*n;
        buildMinHeap(arr, size);

        while(k-1){
            deleteHeap(arr, size);
            k--;
        }

        return arr[0];
    }
};/*T.C. = O(N^2) + O(N^2) + O(KLOG(N^2)) = O(N^2), S.C. = O(N^2)*/