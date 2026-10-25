//PUSH FUNCTION TAKES LOGN--> T.C. = O(NLOGN) + O(KLOGN), S.C. = O(2*(N-1))

class Solution {
public:
    long double minimiseMaxDistance(vector<int> &arr, int k) {
       int n = arr.size();
       vector<int> howMany(n-1, 0);
/*OPTIMISATION : USING PRIORITY QUEUE WITH PAIR TO STORE THE MAX SEC DIFF AT TOP ALONG WITH THE INDEX
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
       */
       priority_queue <pair<long double, int>> pq;
       for(int i = 0; i < n-1; i++){
        pq.push(arr[i+1] - arr[i], i);
       }
       for(int gasStations = 1; gasStations <= k; gasStations++){
        auto tp = pq.top(); pq.pop();
        int secInd = tp.second;
        howMany[secInd]++;
        long double iniDiff = arr[secInd+1] - arr[secInd];
        long double newSecDiff = iniDiff/(long double)(howMany[secInd] + 1);
        tp.push({newSecDiff, secInd});
       }
       return pq.top().first();
    }
};