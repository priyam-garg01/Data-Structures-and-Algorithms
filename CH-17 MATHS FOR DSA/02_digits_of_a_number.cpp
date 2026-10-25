#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


vector<int> getDigits(int n){
    int ans, i = 0;

    vector<int> digits;
    while(n!=0){
        ans = n%10;
        digits.push_back(ans);
        i++;
        n /= 10;
    }
    return digits;
}
int main()
{
    int n = 456777;
    vector<int> digits = getDigits(n);

    // count of n
    cout << (int)(log10(n) + 1) << endl;
    for(int item : digits){
        cout << item << endl;
    }
    return 0;
}