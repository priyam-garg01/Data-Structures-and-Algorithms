#include<iostream>
using namespace std;

class maxHeap{

    int* arr;
    int size;//Total elements in array at present
    int total_size;//Max number of elements that can be stored in arr

    public:
    maxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int val){
        if(size == total_size){
            cout << "Heap Overflow" << endl;
            return;
        }

        //Element addition
        arr[size] = val;
        int index = size;
        size++;

        //Placing of element at its correct position
        while(index > 0){
            int parent = (index - 1)/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
                }
                else break;
            }

            cout << val << " is inserted into the heap"<< endl;
        }

    void maxHeapify(int i){
        if(i > size)return;
        int largest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

            if(left < size && arr[largest] < arr[left])largest = left;
               
            if(right < size && arr[largest] < arr[right])largest = right;

            if(largest != i){
                swap(arr[largest], arr[i]);
                maxHeapify(largest);
            }
        
    }
    void deleteMax(){
        int root = arr[0];
        if(size == 0){
            cout << "Heap Underflow" << endl;
            return;
        }
        int ind = 0;
      
        swap(arr[ind], arr[size-1]);
        size--;
        if(size == 0)return;

        //MaxHeapify
       maxHeapify(0);
        
        cout << root << " is deleted"<< endl;
    }
        void print(){
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    
};
class minHeap{

    int* arr;
    int size;//Total elements in array at present
    int total_size;//Max number of elements that can be stored in arr

    public:
    minHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int val){
        if(size == total_size){
            cout << "Heap Overflow" << endl;
            return;
        }

        //Element addition
        arr[size] = val;
        int index = size;
        size++;

        //Placing of element at its correct position
        while(index > 0){
            int parent = (index - 1)/2;
            if(arr[parent] > arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
                }
                else break;
            }

            cout << val << " is inserted into the heap"<< endl;
        }

    void minHeapify(int i){
        if(i > size)return;
        int smallest = i;
        int left = 2*i + 1;
        int right = 2*i + 2;

            if(left < size && arr[smallest] > arr[left])smallest = left;
               
            if(right < size && arr[smallest] > arr[right])smallest = right;

            if(smallest != i){
                swap(arr[smallest], arr[i]);
                minHeapify(smallest);
            }
        
    }
    void deleteMin(){
        int root = arr[0];
        if(size == 0){
            cout << "Heap Underflow" << endl;
            return;
        }
        int ind = 0;
      
        swap(arr[ind], arr[size-1]);
        size--;
        if(size == 0)return;

        //MaxHeapify
       minHeapify(0);
        
        cout << root << " is deleted"<< endl;
    }
        void print(){
            for(int i = 0; i < size; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    
};


int main(){
    minHeap h1(6);
    h1.insert(8);
    h1.insert(1);
    h1.insert(2);
    h1.insert(7);
    h1.insert(90);
    h1.insert(9);
    
    h1.print(); 
    h1.deleteMin();
    h1.print(); 
    
    cout << "\n" ;
    
    maxHeap h2(6);
    h2.insert(8);
    h2.insert(1);
    h2.insert(2);
    h2.insert(7);
    h2.insert(90);
    h2.insert(9);
    
    h2.print(); 
    h2.deleteMax();
    h2.print(); 


     

}