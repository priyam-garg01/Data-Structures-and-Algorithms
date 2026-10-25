#include <iostream>
using namespace std;
int factorial(int n)
{
    int product = 1;
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            product *= i;
        }
        return product;
    }
}

int nCr(int n, int r)
{
    return factorial(n)/(factorial(r)*factorial(n-r));
}
int main()
{
    cout << nCr(5, 3) << endl;
    
    return 0;
}