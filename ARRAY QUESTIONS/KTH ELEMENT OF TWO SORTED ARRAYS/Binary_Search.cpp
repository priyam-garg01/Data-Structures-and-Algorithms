/*You wrote:

int low = 0;
int high = n1;

This allows invalid partitions.

Remember:

mid1 = elements taken from nums1
mid2 = k - mid1 = elements taken from nums2

We must ensure:

0 <= mid1 <= n1
0 <= mid2 <= n2

Since:

mid2 = k - mid1

That gives:

k - n2 <= mid1 <= k

Combining with array bounds:

max(0, k-n2) <= mid1 <= min(k, n1)

So binary search should start with:

int low = max(0, k - n2);
int high = min(k, n1);



Why your code fails

Example:

nums1 = [2,3]
nums2 = [1]
k = 3

After swap:

nums1 = [1]
nums2 = [2,3]
n1=1, n2=2

Your search:

low=0, high=1

Works here.

But consider:

nums1=[1,2]
nums2=[3,4,5,6,7]
k=6

If mid1=0:

mid2 = 6

But nums2 only has indices 0..4.

Then this line becomes dangerous logically:

if(mid2 < n2) r2 = nums2[mid2];

Since 6 < 5 is false, r2=INT_MAX, which hides the fact that partition is invalid.

So your algorithm may accept invalid partitions.

Fix

Change only this:

int low = max(0, k - n2);
int high = min(k, n1);*/
class Solution {
public:
    int kthElement(vector<int> &nums1, vector<int>& nums2, int k) {
//Similar to the previous problem of finding median we did devise a formula to find median by dividing the merged arr into two equal halves, here we will divide the merged arr into 2 halves where first half contains k elements and second contains n - k elements and our ans will be the last element present in the left half of the merged arr 
   int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1+n2;

        if(n1 > n2){//We are trying to take the smaller arr first according to our code
        return kthElement(nums2, nums1, k);
        }
        int low = max(0, k-n2); int high = min(n1, k);//Here mid1 and mid2 signifies the number of elements brought from resp arr 1 and 2 in the first half or division
        int left = k;//Total elements in one half or first half
        //changed
        /*NOTE: here high and low are wrong as filled the first part k elements high only needs to be upto k means high = min(n1, k) to get the last element from first half
Similarly low should be max(0, k-n2) in cases where k is larger than n2 it will need elements from both arrays saving the burden to ignore the k-n2 elements*/
        while(high >= low){
        int mid1 = (low+high)/2;
        int mid2 = left - mid1;//changed
        //Initially we make the left pointers INT_MIN and right pointers INT_MAX so that if any half is empty of  elements from the nums1 or nums2 it doesnt disturb the comparisons
        int l1 = INT_MIN; int l2 = INT_MIN;
        int r1 = INT_MAX; int r2 = INT_MAX;
        //Only if mid1 is less than n1(the arr with smaller size), then we can assign right element from arr1 as the first half cannot contain more than n1 elements from arr1

        if(mid1 < n1) {
            r1 = nums1[mid1];
            }
        if(mid2 < n2) {
            r2 = nums2[mid2];
            }
        if(mid1 - 1 >= 0){
            l1 = nums1[mid1-1];
            }
        if(mid2 - 1 >= 0){
            l2 = nums2[mid2-1];
            }
        // Comparisons
        if(l1 <= r2 && l2 <= r1){//Case when the first and secod half merges to become a sorted array
            return max(l1, l2);//changed
        }
        else if(l1 > r2) {high = mid1 - 1;}
        else low = mid1 + 1;
    }
    return 0;
  }
};