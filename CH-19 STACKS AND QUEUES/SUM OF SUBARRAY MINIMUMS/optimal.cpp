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

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> pse = findPse(arr);//stores the previous smaller element 
        vector<int> nse = findNse(arr);//stores the next smaller element
        int total = 0;
        int mod = (int)(1e9 + 7);
        for(int i = 0; i < n; i++){
            int prev = i - pse[i];//tells the amount of prev smaller elements to that of arr[i] including that

            int next = nse[i] - i;//tells the amount of next smaller elements to that of arr[i] including that
            total += (prev*next*1LL*arr[i])%mod;
            total %= mod;
        }
        return total;
    }
};/*
//we take the index of each element till which it smallest element from right and left side and on multiplication of that we get how many times it actually contirbutes to the total by finding prev smaller element and next smaller element
T.C. = O(2N)+O(2N) + O(N), S.C. = O(2N)+O(2N) + O(N){FOR THE SINGLE STACK}
T.C. = O(5N) S.C. = O(5N)*/