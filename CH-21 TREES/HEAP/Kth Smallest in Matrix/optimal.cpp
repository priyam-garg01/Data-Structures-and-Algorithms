class Solution {
  public:
    
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int n = matrix.size();
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;

        /*Using the sorted condition that is 1st smallest element will be at {0, 0}and second smallest may be 0,1 or 1,0 and so on ... 
        But we travel only in one direction by storing a full row or col
        */

        for(int i = 0; i < n; i++){
            pq.push({matrix[0][i], {0, i}});//nlogn
        }

        //
    
        //We pushed the elements of row 1 in the priority queue
        int ct = 0;
        int elem, i, j = -1;
        while(ct != k){//klogn
            auto p = pq.top();
            pq.pop();
            ct++;

            elem = p.first;
            i = p.second.first;
            j = p.second.second;

            if(ct == k)return elem;

            else{
                if(i + 1 < n)
                pq.push({matrix[i + 1][j], {i + 1, j}});
            }
        }

        return -1;
    }
};/*T.C. = O(KLOGN + NLOGN) = O(KLOGN), S.C. = O(N)*/