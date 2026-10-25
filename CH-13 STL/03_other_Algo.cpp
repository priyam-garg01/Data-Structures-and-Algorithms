#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // REVERSE
    int arr[5] = {2, 5, 6, 2, 1};
    reverse(arr, arr+5);
    for(int val : arr){
        cout << val <<" ";
    }
    cout << endl;
    vector<int> vec1 = {8, 67, 29, 91, 56 };
        cout << *(max_element(vec1.begin(), vec1.end())) << endl;
    reverse(vec1.begin()+3, vec1.end());
    for(int val : vec1){
        cout << val <<" ";
    }
    cout << endl;
    // NEXT & PREVIOUS PERMUTAION (total n! permutations)
    string s = "abcdefghijklmnop";
    next_permutation(s.begin()+2, s.end());
    for(char val : s){
        cout << val <<" ";
    }
    cout << endl;

    prev_permutation(s.begin()+2, s.end());
    for(char val : s){
        cout << val <<" ";
    }
    cout << endl;

    // Count Set Bits(counts number of bits with value 1)
    int n = 15;
    long int n2 = 8;
    long long int n3 = 5;

    cout << __builtin_popcount(n) << endl;
    cout << __builtin_popcountl(n2) << endl;
    cout << __builtin_popcountll(n3) << endl;

    return 0;
}