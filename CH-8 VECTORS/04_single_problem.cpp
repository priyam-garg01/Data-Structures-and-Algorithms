/*Given a non-empty array of integers nums, 
every element appears twice except for one. 
Find that single one.You must implement a 
solution with a linear runtime complexity 
and use only constant extra space.*/
#include <iostream>
#include <vector>
using namespace std;

int singleNum(vector<int> &nums){
    int ans = 0;
    for(int i : nums)
    {
        ans ^= i;
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,2,1};

    cout << singleNum(nums);

    return 0;
}
