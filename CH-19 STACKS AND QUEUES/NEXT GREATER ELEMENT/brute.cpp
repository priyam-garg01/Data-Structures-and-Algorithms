/*
Given an array arr of size n containing elements, find the next greater element for each element in the array 
in the order of their appearance.
The next greater element of an element in the array is the nearest element on the right that is greater than the current element.
If there does not exist a next greater element for the current element, then the next greater element for that element is -1.
*/
class Solution {
public:
    vector<int> nextLargerElement(vector<int> arr) {
       int n = arr.size();
        vector<int> ans;
       for(int i = 0; i < n; i++){
        int x = arr[i];
        for(int j = i+1; j < n; j++){
            if(arr[j] > x){
                ans.push_back(arr[j]);
                break;
            }
        }
        if(ans.size() != i + 1)ans.push_back(-1);
       }
       return ans;
    }
};//T.C. = O(N^2);
