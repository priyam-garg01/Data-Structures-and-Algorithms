/*Given an array arr[] of positive integers and two integers k1 and k2, find the sum of all array elements whose values lie between the k1-th smallest and the k2-th smallest (both k1th and k2th smallest are not included) of the array.

Examples :

Input: arr[] = [20, 8, 22, 4, 12, 10, 14], k1 = 3, k2 = 6
Output: 26
Explanation: 3rd smallest is 10 and 6th smallest is 20. Sum of all between k1-th and k2-th is 12 + 14 = 26.
Input: arr[] = [1, 2, 3, 4, 5], k1 = 1, k2 = 5
Output: 9
Explanation: 1st smallest is 1 and 5th smallest is 5. Sum of all between k1-th and k2-th is 2 + 3 + 4 = 9.
Input: arr[] = [5, 6, 7], k1 = 2, k2 = 3
Output: 0
Explanation: The 2nd smallest is 6 and the 3rd smallest is 7. Since there are no strictly between 6 and 7, the required sum is 0.
Constraints:
2 ≤ arr.size() ≤ 105
1 ≤ k1< k2 ≤ arr.size()
1 ≤ arr[i] ≤ 2 * 104*/
int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int sum = 0;
        for(int i = k1; i < k2-1; i++){
            sum += arr[i];
        }
        
        return sum;
    }//T.C. = O(NLOGN)
