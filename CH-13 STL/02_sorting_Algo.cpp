#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// Custom Comparator
bool comparator(pair<int, int> p1, pair<int, int> p2){
    // on basis of second elem in the pair

    if(p1.second < p2.second) return true;
    if(p1.second > p2.second) return false;
    // if p1.sec = p2.sec then see first elem
    if(p1.first < p2.first) return true;
    if(p1.first > p2.first) return false;

}
int main()
{
    
    int arr[5] = {2, 5, 6, 2, 1};
    sort(arr, arr+5);
    for(int val : arr){
        cout << val <<" ";
    }
    cout << endl;
// // For Descending order
//     int arr[5] = {2, 5, 6, 2, 1};
//     sort(arr, arr+5, greater<int>());
//     for(int val : arr){
//         cout << val <<" ";
//     }
//     cout << endl;

// For vectors
    vector<int> vec1 = {8, 67, 29, 91, 56 };
    sort(vec1.begin(), vec1.end());
    for(int val : vec1){
        cout << val <<" ";
    }
    cout << endl;
// For vector pair
    vector<pair<int, int>> vec = {{86,7}, {6, 45}, {34, 1}, {6, 90}};
    sort(vec.begin(), vec.end());
    for(auto p : vec){
        cout << p.first <<" " << p.second<< "  ";
    }
    // Custom comparator 
    cout << endl;
    vector<pair<int, int>> vec2 = {{86,7}, {6, 45}, {34, 7}, {6, 90}};
    sort(vec2.begin(), vec2.end(), comparator);
    for(auto p : vec2){
        cout << p.first <<" " << p.second<< "  ";
    }
    cout << endl;

    
    return 0;
}