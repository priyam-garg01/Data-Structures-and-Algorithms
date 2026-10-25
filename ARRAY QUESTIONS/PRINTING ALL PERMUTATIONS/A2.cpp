// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void recurPermute(int index, vector<vector<int>> &ans, vector<int> &nums){
    if(index == nums.size()){
        ans.push_back(nums);
        return;
    }
    for(int i = index; i < nums.size(); i++){
        swap(nums[index], nums[i]);
        recurPermute(index+1, ans, nums);
        swap(nums[index], nums[i]);
    }
}


vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    int index;
    
    recurPermute(0, ans, nums);
    return ans;
}
int main() {
   vector<int> nums;
   nums = {1, 4, 12};
   int n = nums.size();

   vector<vector<int>> p;

   p = permute(nums);
   int k = p.size();

    vector<int> result;
   for(int i = 0; i < k; i++){
    result = p[i];
        for(int j = 0; j < n; j++){
        cout << result[j] << endl;
    }
    cout << endl;
   }
    return 0;
}