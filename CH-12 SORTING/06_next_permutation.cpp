#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int> &nums)
{
    int n = nums.size();
    // Finding pivot element
    int pivot = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    // Agar descending order mai array hua ex:[5,4,3,2,1]
    // then just rev array
    if (pivot == -1)
    {
        // reverse(nums.begin(), nums.end());//in place changes
        int i = 0, j = n - 1;
        while (i <= j)
        {
            swap(nums[i], nums[j]);
            i++, j--;
        }
        return;
    }

    // Finding rightmost element for swapping
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[pivot] < nums[i])
        {
            swap(nums[pivot], nums[i]);
            break;
        }
    }


    // Remaining array in descending order
    // reverse(piv+1, n-1)

    // // reverse(nums.begin() + pivot + 1, nums.end());//in place changes
    int a = pivot + 1, b = n - 1;
    while (a <= b)
    {
        swap(nums[a++], nums[b--]);
    }
}

int main()
{

    vector<int> a = {1, 5, 8, 98};
    nextPermutation(a);
    // next_permutation(a.begin(), a.end());

    for(int i = 0; i < a.size(); i++){
        cout << a[i] << endl;
    }
    return 0;
}