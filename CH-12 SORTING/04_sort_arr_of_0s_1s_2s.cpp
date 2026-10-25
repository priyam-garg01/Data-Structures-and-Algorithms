#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// // BRUTE FORCE
// void sortColors(vector<int> &arr)
// {
//     sort(arr.begin(), arr.end());
//     // T.C. = O(nlog(n)), S.C. = O(1)(no extra space)
// }


// DNF ALGORITHM
// T.C. = O(n)(with single loop), S.C. = O(1)
void sortColors(vector<int> &arr)
{
    int n = arr.size();
    int low = 0, mid = 0, high = n-1;
    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++, low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else
        // arr[mid] == 2
        {
            swap(arr[mid], arr[high]);
            high--;
        }

    }
}

// // OPTIMISED APPROACH(T.C = O(n))
// void sortColors(vector<int> &arr)
// {
//     int n = arr.size();
//     // T.C. = O(n)
//     int count0 = 0, count1 = 0, count2 = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == 0)
//         {
//             count0++;
//         }
//         else if (arr[i] == 1)
//         {
//             count1++;
//         }
//         else
//         {
//             count2++;
//         }
        
//     }

// //   T.C = O(n)
//     int idx = 0;
//     for(int i = 0; i < count0; i++)
//     {
//         arr[idx++] = 0;
//     }
//     for(int i = 0; i < count1; i++)
//     {
//         arr[idx++] = 1;
//     }
//     for(int i = 0; i < count2; i++)
//     {
//         arr[idx++] = 2;
//     }


// // OR
//     // for(int i = 0; i < count0; i++){
//     //     arr[i] = 0;
//     // }
//     // for(int i = count0; i < count0 + count1; i++){
//     //     arr[i] = 1;
//     // }
//     // for(int i = count0 + count1; i < n; i++){
//     //     arr[i] = 2;
//     // }
// }
    int main()
    {
        vector<int> nums = {2, 0, 2, 1, 1, 0, 1, 2, 0, 0};

        sortColors(nums);

        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i] << endl;
        }
        return 0;
    }