class Solution {
  public:
    void mergeSort(vector<int>& arr, int st, int end, int m, int k){
        if(k < 2)return;//That is only 1 array is left that is already sorted
        
        int mid = st + (k/2)*m - 1;//k ->number of arrays with size m
        
        mergeSort(arr, st, mid, m, k/2);
        mergeSort(arr, mid + 1, end, m, k - k/2);
        merge(arr, st, mid, end, m);
    }
    void merge(vector<int>& arr, int st, int mid, int end, int m){
        if(st == end)return;
        
        vector<int> merged;
        int i = st;
        int j = mid + 1;
        
        while(i <= mid && j <= end){
            if(arr[i] <= arr[j]){
                merged.push_back(arr[i++]);
            }
            else{
                merged.push_back(arr[j++]);
            }
        }
        while(i <= mid){
            merged.push_back(arr[i++]);
        }
        
        while(j <= end){
            merged.push_back(arr[j++]);
        }
        
        int k = 0;
        
        for(int i = st; i <= end; i++){
            arr[i] = merged[k++];
        }
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {

        int k = mat.size();//arrCt
        int m = mat[0].size();//arrSize
        
        vector<int> mergedArray;
        for(int i = 0; i < k; i++){//O(M*K)
            for(int j = 0; j < m; j++){
                mergedArray.push_back(mat[i][j]);
            }
        }
     //We use the mergeSort logic of dividing and merging but since we are given sorted arrays we divide them in sorted parts(k)
        mergeSort(mergedArray, 0, m*k -1, m, k);//O(m*klogk)
       
        return mergedArray;
    }//T.C. = O(M*KLOGK), S.C. = O(M*K)
};