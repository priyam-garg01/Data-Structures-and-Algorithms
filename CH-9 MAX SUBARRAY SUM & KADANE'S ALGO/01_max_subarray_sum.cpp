#include <iostream>
using namespace std;

int main()
{
    // // Printing of subarrays
    //     int nums[] = {1, 2, 3, 4, 5};
    //     int st, end;

    //     for(st = 0; st < 5; st++){
    //         for(end = st; end < 5; end++){
    //             for(int i = st; i <= end; i++){
    //                 cout << nums[i];
    //             }
    //             cout << " ";
    //         }
    //         cout << endl;
    //     } /*
    //     1 12 123 1234 12345 starting from index 0
    //     2 23 234 2345       starting from index 1
    //     3 34 345            starting from index 2
    //     4 45                starting from index 3
    //     5                   starting from index 4
    // */

    // Finding max subarray sum
        int nums1[] = {1, 2, -3, 4, -5};

        int st, end;
        int maxSum = INT16_MIN, currentSum = 0;

        for(st = 0; st < 5; st++){
            for(end = st; end < 5; end++){
                currentSum += nums1[end];
                maxSum = max(currentSum, maxSum);
                }
            }
            cout <<"Maximum sum is : " <<  maxSum;

    // // Finding max subarray sum using KADANE'S ALGO

    // int nums1[] = {1, 2, -3, 4, -5};

    // int maxSum = INT32_MIN, currentSum = 0;

    // for (int i = 0; i < 5; i++)
    // {

    //     currentSum += nums1[i];
    //     maxSum = max(currentSum, maxSum);
    //     if (currentSum < 0)
    //     {
    //         currentSum = 0;
    //     }
    // }
    // cout << "Maximum sum is : " << maxSum;

    return 0;
}