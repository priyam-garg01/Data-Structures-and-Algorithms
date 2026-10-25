// // Online C++ compiler to run C++ program online
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// vector<int> leaders(vector<int>& nums) {
//         int n = nums.size();
//         vector<int> result;
//       for(int i = 0; i < n - 1; i++){
//         auto it = max_element(nums.begin() + i + 1, nums.end());
//         if(nums[i] > *it){
//             result.push_back(nums[i]);
//         }
//         }
//         result.push_back(nums[n-1]);
//       return result;
//     }
// int main() {
//    vector<int> nums = {2, 1, 5, 3, 1, 2};
//    int n = nums.size();
//    vector<int> result;
//    result = leaders(nums);
//    int nR = result.size();
   
//    for(int i = 0; i < nR; i++){
//        cout << result[i] << endl;
//    }

//     return 0;
// }


// OR
// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> leaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        int max = INT8_MIN;
      for(int i = n-1; i >=0; i--){
        if(nums[i] > max){
            max = nums[i];
            result.push_back(nums[i]);
        }
        }
      return result;
    }

int main() {
   vector<int> nums = {2, 1, 5, 3, 1, 2};
   int n = nums.size();
   vector<int> result;
   result = leaders(nums);

//    foractual order as in array
reverse(result.begin(), result.end());
   int nR = result.size();
   
   for(int i = 0; i < nR; i++){
       cout << result[i] << endl;
   }

    return 0;
}