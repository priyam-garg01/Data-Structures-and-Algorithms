// Return a pair in a sorted(ascending or descending)
// array with target sum
// arr = {2, 7, 11, 15}
// target sum = 9
#include <iostream>
#include <vector>
using namespace std;

// // Brute force approach (n^2)
// vector<int> pairSum(vector<int> nums, int target)
// {
//     vector<int> ans;
//     int n = nums.size();

//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] + nums[j] == target)
//             {
//                 // indexes of array is pushed in ans vector
//                 ans.push_back(i);
//                 ans.push_back(j);
//                 return ans;
//             }
//         }
//     }
//     return ans;
// }

// 2-pointer approach (n)
vector<int> pairSum(vector<int> nums, int target)
{
    vector<int> ans;

    int n = nums.size();
    int i = 0, j = n-1;
    while(i < j){
        int pairSum = nums[i] + nums[j];
        if(pairSum < target){
            i++;
        }
        else if(pairSum > target){
            j--;
        }
        else{
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
    }
    
}
int main()
{
    vector<int> arr = {2, 7, 11, 15};
    int tagetSum = 26;

    vector<int> ans = pairSum(arr, tagetSum);

    cout << ans[0] << ", " << ans[1] << endl;

    return 0;
}