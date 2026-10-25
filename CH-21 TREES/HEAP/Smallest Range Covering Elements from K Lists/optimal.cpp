/*class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        //Better: We use a min priority queue and keep entering 1 element from each list every time we want to shorten our range to find the smallest range

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        int maxi = INT_MIN;
        for(int i = 0; i < k; i++){
            pq.push({nums[i][0], {i, 0}});//Notes the element and the list index
            maxi = max(maxi, nums[i][0]);
        }
     
        vector<int> minRange = {pq.top().first, maxi};
        while(pq.size() == k){
            int minElem = pq.top().first;
            int ListIdx = pq.top().second.first;
            int minListIdx = pq.top().second.second;
            pq.pop();
            if(minListIdx + 1 < nums[ListIdx].size()){
                pq.push({nums[ListIdx][minListIdx + 1], {ListIdx, minListIdx + 1}});
            if(nums[ListIdx][minListIdx + 1] > maxi){
                maxi = nums[ListIdx][minListIdx + 1];
            }
            int newRange = maxi - pq.top().first;
            
            if(minRange[1] - minRange[0] > newRange){
                minRange = {pq.top().first, maxi};
            }
            }
        }
    return minRange;
    }
};
*/
/*Primary Issue:
Because you update minRange after popping and pushing a new element, the range maxi - pq.top().first evaluates a window that skips the current minElem.
Extract minElem from pq.top().
Check if maxi - minElem < minRange[1] - minRange[0]. If true, update minRange = {minElem, maxi}.
Pop from pq.
If a next element exists in that list, push it and update maxi.
If no next element exists, break the loop immediately */
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int k = nums.size();
        
        //Better: We use a min priority queue and keep entering 1 element from each list every time we want to shorten our range to find the smallest range

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        int maxi = INT_MIN;
        for(int i = 0; i < k; i++){//T.C. = O(K)
            pq.push({nums[i][0], {i, 0}});//Notes the element and the list index
            maxi = max(maxi, nums[i][0]);
        }
     
        vector<int> minRange = {pq.top().first, maxi};
        while(pq.size() == k){//T.C. = O(N*K*logK), S.C. = O(K)
            int minElem = pq.top().first;
            int ListIdx = pq.top().second.first;
            int minListIdx = pq.top().second.second;
            pq.pop();
    
            int newRange = maxi - minElem;
            if(minRange[1] - minRange[0] > newRange){
                minRange = {minElem, maxi};
                }

            if(minListIdx + 1 < nums[ListIdx].size()){
                int nextVal = nums[ListIdx][minListIdx + 1];
                pq.push({nextVal, {ListIdx, minListIdx + 1}});
                maxi = max(maxi, nextVal);
            }
            else{
                break;//A list is exhausted
            }
        }
    return minRange;
    }
};