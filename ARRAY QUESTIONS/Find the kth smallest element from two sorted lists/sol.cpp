class Solution{
    int findKthSmallestElement(list<int> l1, list<int> l2, int k){

        auto it1 = l1.begin();
        auto it2 = l2.begin();

        int count = 0;
        
        while(it1 != l1.end() && it2 != l2.end()){
            count++;

            if(*it1 < *it2){
                if(count == k)return *it1;
                it1++;
            }
            else{
                if(count == k)return *it2;
                it2++;
            }

            //If still count hasnt reached k then
            while(it1 != l1.end()){
                count++;
                if(count == k)return *it1;
                it1++;
            }
            while(it2 != l2.end()){
                count++;
                if(count == k)return *it2;
                it2++;
            }
        }
        return -1;// if the kth smallest element isnt found
        
    }
};//T.C. = O(M+N), S.C. = O(1)