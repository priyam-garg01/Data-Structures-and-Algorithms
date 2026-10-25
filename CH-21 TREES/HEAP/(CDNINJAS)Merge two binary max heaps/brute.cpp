/*You are given two integer arrays ‘ARR1’ and ‘ARR2’ of size ‘N’ and ‘M’ respectively, Both ‘ARR1’ and ‘ARR2’ represent a Max-Heap. Your task is to merge the two arrays firstly keep all the elements of the ‘ARR1’ (without changing order) than elements of array ‘ARR2’ (without changing order), and then find the Max-Heap obtained by merging arrays. Print an array of sizes ‘N + M’, representing the Max-Heap obtained after merging.

A binary Max-Heap is a complete binary tree in which the value in each internal node is greater than or equal to the values in the children of that node.

Max-Heaps are usually represented by an array, as follows :

1. Each element in the array represents a node of the heap.

2. Element at index 0 represent the root of the heap.

3. If a node is represented by elements at index ‘i’ then its left and right child is represented by elements at indices ‘2*i + 1’ and ‘ 2*i + 2’  respectively.
Example :
Consider ‘ARR1’ = [10, 5, 6, 2] and ‘ARR2’ = [12, 7, 9]. */
#include <bits/stdc++.h> 

vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++){
            pq.push(arr1[i]);
        }

        for(int j = 0; j < m; j++){
            pq.push(arr2[j]);
        }

        vector<int> mergedHeap;
        while(!pq.empty()){
            mergedHeap.push_back(pq.top());
            pq.pop();
        }

    return mergedHeap;
}//T.C. = O((N + M)LOG(N+M)), S.C. = O(N + M)