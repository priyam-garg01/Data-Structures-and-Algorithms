//Use a vector to store the gas stations inserted b/w the consective gas stations by altering the section length obseving (long double for ans)
// the maximum of the secLen remaining by looping the the arr inside the count of gas stations
// after storing that run another loop to check diff and check the max secLen
// T.C. = O(K*N), S.C. = O(N-1);




class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howMany(n-1, 0);

       for(int gasStations = 1; gasStations <= k; gasStations++){
        long double maxValue = -1;
        int maxInd = -1;
        for(int i = 0; i < n-1; i++){
            long double diff = arr[i+1] - arr[i];
            long double sectionLen = diff/(long double)(howMany[i] + 1);
            if(sectionLen > maxValue){
                maxValue = sectionLen;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
       }
        long double maxAns = -1;
       for(int i = 0; i < n-1; i++){
            long double diff = arr[i+1] - arr[i]; 
            long double sectionLen = diff/(long double)(howMany[i] + 1);
            maxAns = max(maxAns, sectionLen);
       }
       return maxAns;
    }
};