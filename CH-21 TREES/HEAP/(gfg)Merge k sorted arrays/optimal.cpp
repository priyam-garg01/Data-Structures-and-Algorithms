class Solution {
  public:
  
    void merge(vector<int>& v1, vector<int>& v2){
        vector<int> merged;
        int i, j; 
        i = j = 0;
    
        while(i < v1.size() && j < v2.size()){
            if(v1[i] > v2[j]){
                merged.push_back(v2[j++]);
            }
            else{
                merged.push_back(v1[i++]);
            }
        }
        
        while(i < v1.size()){
            merged.push_back(v1[i++]);
        }
        
        while(j < v2.size()){
            merged.push_back(v2[j++]);
        }
        v1 = merged;
    }
    vector<int> mergeArrays(vector<vector<int>> &mat) {

        int k = mat.size();//arrCt
        int m = mat[0].size();//arrSize
        
        //Move only the first elements of the array into the priorityQ and when removing them add their corresponding next element
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
        //Notes the jth element of that ith array with element and i and j
        //S.C. = O(K)
        for(int i = 0; i < k; i++){
            pq.push({mat[i][0], {i, 0}});//O(klogk)
        }
        
        vector<int> mergedArray;
        while(!pq.empty()){//O(n*klogk)
            auto p = pq.top();
            pq.pop();
            mergedArray.push_back(p.first);
            int i = p.second.first;
            int j = p.second.second;
            if(j + 1 < m)pq.push({mat[i][j + 1], {i, j + 1}});
        }
        return mergedArray;
    }//T.C. = O(M*KLOGK), S.C. = O(K)
};//Alternate method store the elements in the ans vector(N*M) and apply heap sort on it ==> T.C. = O(N*MLOG(N*M)) == O(N^2LOGN^2) = N^2LOGN, S.C. = O(1);