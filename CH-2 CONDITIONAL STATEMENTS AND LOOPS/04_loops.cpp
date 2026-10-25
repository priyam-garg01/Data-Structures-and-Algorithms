#include<iostream>
using namespace std;

int main(){
// // Print numbers from 1-n
// int n;
// cout << "Enter the number: ";
// cin >> n;

//     for(int i = 1; i < n+1; i++){
//         cout << i << endl;
// }
// cout << "\n";

//     int j = 1;
//     while(j < n+1){
//         cout << j << endl;
//         j++;
//     }
//     cout << "\n";

//     int k = 1;
//     do{
//             cout << k << endl;
//             k++;
//     }
//     while(k < n + 1 );

// // Print sum of numbers from 1-n
// int sum = 0;
// int n1;
// cout << "Enter the number: ";
// cin >> n1;

//     for(int i = 1; i < n1+1; i++){
//         sum += i;
//     }

//     cout << "Sum of numbers from 1 to "<< n1 << " is: "<< sum << endl;
    

//     // int j = 1;
//     // while(j < n1+1){
//     //     sum += j;
//     //     j++;
//     // }
//     // cout << "Sum of numbers from 1 to "<< n1 << " is: "<< sum << endl;
    

//     int k = 1;
//     do{
//         sum += k;
//         k++;
//     }
//     while(k < n1 + 1 );
//     cout << "Sum of numbers from 1 to "<< n1 << " is: "<< sum << endl;

// Print all even numbers upto n
    // int n2;
    // cout << "Enter the number: ";
    // cin >> n2;

    // for(int i = 0; i < n2+1; i++){
    //     if((i % 2) != 0)
    //     continue;
    //     cout << i << endl;
    // }
    // int j =1;
    // while(j < n2+1){
    //     if((j % 2) != 0){
    //     j++;
    //     continue;
    // }
    //     cout << j << endl;
    //     j++;
    // }

    // int k = 1;
    // do{
    //     if((k % 2) != 0){
    //     k++;
    //     continue;
    // }
    //     cout << k << endl;
    //     k++;
    // }
    // while(k < n2+1);


// Sum of all odd numbers from 1 to n

    // int n3;
    // cout << "Enter the number: ";
    // cin >> n3;
    // int oddSum = 0;

    // for(int i = 1; i < n3+1; i += 2){
    //     oddSum += i;
    // }
    //     cout << oddSum << endl;

    // int j = 1;
    // while(j < n3+1){
    //     oddSum += j;
    //     j += 2;
    // }    
    // cout << oddSum << endl;

    // int k =1;
    // do{
    //     oddSum += k;
    //     k +=2;
    // }
    // while(k < n3+1);

    // cout << oddSum << endl;


// Sum of all numbers from 1 to n to which are divisible by 3
    int n4;
    cout << "Enter the number: ";
    cin >> n4;
    int sum3 = 0;

    // for(int i = 1; i < n4+1; i++){
    //     if(i %3 ==0)
    //         sum3 += i;
    // }
    // cout << sum3 << endl;

    // int j = 1;
    // while(j < n4+1){
    //    if(j %3 ==0)
    //         sum3 += j;
    //    j++;
    // }    
    // cout << sum3 << endl;


// Print factorial of a number n
    int prod = 1;

    // for(int i = 1; i < n4+1; i++)
    //     prod *= i;

    // cout << "The factorial of "<<n4 <<" is "<< prod << endl;

    int j = 1;
    while(j < n4+1){
        prod *= j;
        j++;
    }
    cout << "The factorial of "<<n4 <<" is "<< prod << endl;
    return 0;
}