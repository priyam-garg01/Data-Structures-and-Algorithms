/*You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
Given the integer array fruits, return the maximum number of fruits you can pick.

 

Example 1:

Input: fruits = [1,2,1]
Output: 3
Explanation: We can pick from all 3 trees.
Example 2:

Input: fruits = [0,1,2,2]
Output: 3
Explanation: We can pick from trees [1,2,2].
If we had started at the first tree, we would only pick from trees [0,1].
Example 3:

Input: fruits = [1,2,3,2,2]
Output: 4
Explanation: We can pick from trees [2,3,2,2].
If we had started at the first tree, we would only pick from trees [1,2].
 

Constraints:

1 <= fruits.length <= 105
0 <= fruits[i] < fruits.length*/
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        //here fruits[i] doesnt represent the number of fruits but the type of fruits like type 1, type 0, ....
        //This problem can be simplified into finding the longest subarray with atmost 2 different integers
        int maxCt = 0;
        for(int i = 0; i < n; i++){
            int basket1 = -1; int basket2 = -1;
            int len = 0;
            for(int j = i; j < n; j++){
                if(basket1 == -1){
                    basket1 = fruits[j];
                }
                else if(basket2 == -1 && fruits[j] != basket1){
                    basket2 = fruits[j];
                }

                if(fruits[j] == basket1 || fruits[j] == basket2){
                    len = j - i + 1;
                    maxCt = max(maxCt, len);     
                }
                else break;
            }
        }
        return maxCt;
    }
};/*T.C. = O(N2), S.C. = O(1)
We can also take a set and insert elements in that, keeping the condition the size id less than or equal to k*/