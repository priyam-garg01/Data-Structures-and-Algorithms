class Solution {
public:

vector<int> findPse(vector<int> arr){//here we will store the indexes of elements in vector
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] < arr[st.top()])st.pop();
//here we do not take than equal to as situation may arise that arr has same elements only({1, 1}) in that case the subarray {1,1} might be added twice
        if(st.empty()){
            ans[i] = -1;//this remains same as it is from the left side
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;

}
vector<int> findNse(vector<int> arr){//here we will store the indexes of next element in the vector
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] <= arr[st.top()])st.pop();
 
        if(st.empty()){
            // ans[i] = -1; change to n for calc
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;

}

    long long sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pse = findPse(arr);//stores the previous smaller element 
        vector<int> nse = findNse(arr);//stores the next smaller element
        long long total = 0;
        // here there is no need of mod otherwise the ans completely changes
        // int mod = (int)(1e9 + 7);
        for(int i = 0; i < n; i++){
            int prev = i - pse[i];//tells the amount of prev smaller elements to that of arr[i] including that

            int next = nse[i] - i;//tells the amount of next smaller elements to that of arr[i] including that
            total += (prev*next*1LL*arr[i]);
          
        }
        return total;
    }
vector<int> findPle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[i] > arr[st.top()])st.pop();

        if(st.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
vector<int> findNle(vector<int> arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--){
        while(!st.empty() && arr[i] >= arr[st.top()])st.pop();

        if(st.empty()){
            ans[i] = n;
        }
        else{
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
    long long sumSubarrayMaxs(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> ple = findPle(arr);//stores the previous larger element 
        vector<int> nle = findNle(arr);//stores the next larger element
        long long total = 0;
        // here there is no need of mod otherwise the ans completely changes
        // int mod = (int)(1e9 + 7);
        for(int i = 0; i < n; i++){
            int prev = i - ple[i];//tells the amount of prev smaller elements to that of arr[i] including that

            int next = nle[i] - i;//tells the amount of next smaller elements to that of arr[i] including that
            total += (prev*next*1LL*arr[i]);
           
        }
        return total;
    }

    long long subArrayRanges(vector<int>& arr) {
        int n = arr.size();
        long long maxSum = sumSubarrayMaxs(arr);
        long long minSum = sumSubarrayMins(arr);
        long long range = maxSum-minSum;
        //this can be solb=ved by subtracting the subarray sum of maximums and subarray sum of minimums

        return range;
    }
};/*this can be solved by subtracting the subarray sum of maximums and subarray sum of minimums
1) remove the % by mod in the previous problems
2) convert the final total to long long as ans is in long long
T.C. = O(5N)*2 , S.C. = O(5N)*2 */