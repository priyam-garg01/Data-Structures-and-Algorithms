/*You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.

We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.

 

Example 1:

Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
Output: [20,24]
Explanation: 
List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
List 2: [0, 9, 12, 20], 20 is in range [20,24].
List 3: [5, 18, 22, 30], 22 is in range [20,24].
Example 2:

Input: nums = [[1,2,3],[1,2,3],[1,2,3]]
Output: [1,1]
 

Constraints:

nums.length == k
1 <= k <= 3500
1 <= nums[i].length <= 50
-105 <= nums[i][j] <= 105
nums[i] is sorted in non-decreasing order.*/
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        //Brute force: Take ranges in pairs of all the n*k elements and compare with other n*k elements if they comes in that by flattening the lists
        
        vector<pair<int, int>> allElements;
        // 1. Flatten all elements into a single vector
        for(int i = 0; i < k; i++){
            for(int num : nums[i]){
                allElements.push_back({num, i});
            }
        }

        // 2. Sort all elements based on their value
        sort(allElements.begin(), allElements.end());

        int minRangeLen = INT_MAX;
        vector<int> result = {0, 0};

        // 3. Check every pair of start and end indices
        for(int i = 0; i < allElements.size(); i++){
            unordered_map<int, int> count;
            int distinctLists = 0;
            for(int j = i; j < allElements.size(); j++){
                int listIdx = allElements[j].second;

                if(count[listIdx] == 0){
                    distinctLists++;
                }
                count[listIdx]++;

                //If range [i, j] covers at least one element from all k lists
                if(distinctLists == k){
                    int currentRange = allElements[j].first - allElements[i].first;
                    if(currentRange < minRangeLen) {
                        minRangeLen = currentRange;
                        result = {allElements[i].first, allElements[j].first};
                    }
                    break; //Move to the next starting point 'i'
                }
            }
        }
        return result;//T.C. = O((N*K)*N*K), S.C. = O(N*K)
    }
};//TLE