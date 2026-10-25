//T.C. = O(LOG(10^^9)*m*log(n)), S.C. = O(1)

class Solution{//GIVEN: that m*n == odd
public:
int upperBound(vector<int> & arr, int x, int n/*(size)*/){
    int low = 0; int high = n-1;
    int ans = n;
    while(low <= high){
        int mid = (low + high)/2;

        //maybe an answer
        if(arr[mid] > x){
            ans = mid;
            //look for small index
            high = mid - 1;
        }
        else low = mid + 1;
    }
    return ans;
}

int countSmallerEqual(vector<vector<int>> &matrix, int m, int n, int x){
    int count = 0;
    for(int i = 0; i < m; i++){
        count += upperBound(matrix[i], x, n);// 'n' --> Upper bound will be checked in each row
    }
    return count;
}


    int findMedian(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
    // We can use binary search on the search space of min element in the matrix to that of the highest element in the matrix
    // Smallest and largest element can be found by accessing the first and the last column of the matrix since the matrix is row sorted
    int low = INT_MAX, high = -1;
    for(int i = 0; i < m; i++){
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }
    //Now we apply binary search on the number of elements <= mid in the matrix --> This smaller than or equal to elements will be found by the function which will iterate through each row and check the upperbound of that mid element and count will be incremented as follwed
    while(low <= high){
        int mid = (low+high)/2;
        int smallEqual = countSmallerEqual(matrix, m, n, mid);
        if(smallEqual > (m*n)/2){
            high = mid - 1;
        }
            else low = mid + 1;
        
    }
    return low;
    }
};