/*Use binary search with a little optimization such as: high >= low --> high-low >1e-6(representing that the distance between two consecutive stations is greater than 6 decimal places)
Input low to zero as distance can be zero if all the gas stations are placed at one location and high can as max as the max distance already present in arr initially
Then build a count gas stations function and alter the low equal to mid or high equal to mid as the range space is needed because distance is in long double and not integer
T.C. = O(NLOGN), S.C. = O(1);
*/




class Solution {
public:

    int numberOfGasStationsReq(long double distance, vector<int> &arr){
        int count = 0;
        for(int i = 1; i < arr.size(); i++){
            int numberInBetween = ((arr[i] - arr[i-1])/distance);
            if(((arr[i] - arr[i-1])/distance) == numberInBetween*distance){
                numberInBetween--;
            }
            count += numberInBetween;
        }
        return count;
    }
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
    //Using the B.S. for answers the range of answers is 0 to maximum distance initially in the arr
    // zero if all the gas stations are present at same location

    long double low = 0; long double high = 0; long double mid;
//initiating high to max distance initially present in arr elemetns
    for(int i = 0; i < n-1; i++){
        high = max(high, (long double)arr[i+1] - arr[i]);
    }

//if the ditance b/w consecutive gasStations is lesser than 6 decimal places the loop ends as the code only gives importance to ans upto 6 decimal places

// since distance is long double we will not use high >= low, low = mid+1, high = mid-1;
long double diff = 1e-6;
    while(high - low  > diff){
        mid = (high+low)/2.0;
        int cnt = numberOfGasStationsReq(mid , arr);
        if(cnt > k){//it means distance is less
            low = mid;
        }
        else
            high = mid;
    }
       return high;
    }
};