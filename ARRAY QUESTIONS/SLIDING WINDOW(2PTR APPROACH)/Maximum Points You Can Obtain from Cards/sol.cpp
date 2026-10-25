/*There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

 

Example 1:

Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.
Example 2:

Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.
Example 3:

Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
 

Constraints:

1 <= cardPoints.length <= 105
1 <= cardPoints[i] <= 104
1 <= k <= cardPoints.length*/
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
    int leftS = 0;
    int rightS = 0;
    for(int i = 0; i < k; i++){
        leftS += cardPoints[i];
    }
    //now we will will compare the max by added one element from right and excluding one left element changing the left and right sum

    int maxS = leftS;
    int l = k-1;
    int r = n-1;
    while(k){
        rightS += cardPoints[r];
        r--;
        leftS -= cardPoints[l];
        l--;
        maxS = max(maxS, leftS+rightS);
        k--;
    }
    return maxS;














        //two pointers one to the end and another to the front

        // int left = 0;  
        // int right = n-1;
        // int sum = 0;
        
        // while(right >= 0 && left < n && k){
        //     if(cardPoints[left] == cardPoints[right]){
        //         sum += cardPoints[left];
        //         left++; 
        //        // right--;//moving both the pointers is not right as we havnt picked both the cards the card with same point still exits on one end and we cant move further w/o counting it
        //     }
        //     else if(cardPoints[left] > cardPoints[right]){
        //         sum += cardPoints[left++];
        //     }
        //     else if(cardPoints[left] < cardPoints[right]){
        //         sum += cardPoints[right--];
        //     }
        //     k--;
        // }
        // return sum;

        //Using this approach we if left and right elements are equal we need to know their next and previous elements resp to know which side to move otherwise incorrect ans is observed
    }
};
// T.C. = O(2K)