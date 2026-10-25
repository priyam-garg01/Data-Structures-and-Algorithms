// WAF to print the intersection of 2 arrays
using namespace std;
#include <iostream>

void intersecArray(int arr1[], int arr2[], int s1, int s2){
    bool visited[s2] = {false};

    for(int i =0; i < s1; i++){
        for(int j = 0; j < s2; j++){
            if(arr1[i] == arr2[j] && !visited[j]){
                cout << arr1[i]<< endl;
                visited[j] = true;
                break;
            }
        }
    }
}
int main()
{
    int arr1[] = {4, 2, 6, 8 ,9, 8, 8};
    int arr2[] = {4, 2, 3, 8 ,10};

    intersecArray(arr1, arr2, 7, 5);
    return 0;
}