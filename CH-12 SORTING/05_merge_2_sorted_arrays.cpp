#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// //By taking a third variable(Extra space)
// void mergeSortedArrays(vector<int> &a, int m, vector<int> &b, int n){
//     vector<int> c;
    
//     int i = 0, j = 0;

//     while(i < m && j < n){
//         if(a[i] <= b[j]){
//             c.push_back(a[i]);
//             i++;
//         }
//         else{
//             c.push_back(b[j]);
//             j++;
//         }

//         // Remaining elements
//         while (i < m){
//             c.push_back(a[i]);
//             i++;
//         }
//         while(j < n){
//             c.push_back(b[j]);
//             j++;
//         }
        
        
//     }
    
// }

void mergeSortedArrays(vector<int> &a,int m,vector<int> &b, int n){
    int idx = m + n - 1, i = m - 1, j = n - 1;
    while(i >= 0 && j >= 0){
        if(a[i] >= b[j]){
            a[idx] = a[i];
            idx--, i--;
        }
        else //a[i] < b[j]
            {a[idx] = b[j];
            idx--, j--;
            }
    }
    while(j >= 0){
        a[idx] = b[j];
        idx--, j--;
    }

}

int main()
{
    vector<int> a = {4, 5, 6, 0, 0, 0};

    vector<int> b = {1, 2, 3};

    mergeSortedArrays(a, 3, b, 3);

    for(int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }



    return 0;
}