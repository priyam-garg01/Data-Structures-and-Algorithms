// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

void recurPermute(vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int freq[]){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for(int i = 0; i < nums.size(); i++){
        if(!freq[i]){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, ans, nums, freq);//PICK OR TAKE
            freq[i] = 0;
            ds.pop_back();//NOT TAKE
    }
}
}

vector<vector<int>> permute(vector<int> &nums){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()] = {0};
    recurPermute(ds, ans, nums, freq);
    return ans;
}
int main() {
   vector<int> nums;
   nums = {1, 4, 2, 98, 12};
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