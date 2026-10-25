/*
Use merge sort with one tweak to increment count 
whenever lower index element nums[i] is greater
or we can return count from each merge function and merge sort function as output
and return that only
S.C. = O(N) FOR WITHOUT ALTERING DATA


*/


class Solution {
public:
    long long count = 0;
    void merge(vector<int> &nums,int low,int mid,int end){
        vector<int> temp;
        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= end){
            if(nums[j] >= nums[i]){
                temp.push_back(nums[i]);
                i++;
                
            }
            else{
                temp.push_back(nums[j]);
                count += mid - i + 1;//Just a simple addition to check if smallest element of one array is greater than all its elemnts are
                j++;
            }
        }

        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= end){
            temp.push_back(nums[j]);
            j++;
        }

        for(int k = low; k <= end; k++){
            nums[k] = temp[k-low];
        }
        return;
    }
    void mergeSort(vector<int> &nums,int low,int end){
        if(low >= end)return;
        int mid = low + (end-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, low, mid, end);
        return;
        
    }
   long long int numberOfInversions(vector<int> nums) {

    int n = nums.size();
    mergeSort(nums, 0, n-1);
    return count;

    }
};