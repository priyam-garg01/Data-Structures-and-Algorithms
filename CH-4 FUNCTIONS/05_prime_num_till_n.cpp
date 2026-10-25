#include <iostream>

using namespace std;

int prime_num(int n)
{
    int prime;
    if (n == 0 || n == 1)
    {
        prime = 0;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                prime = 0;
                break;
            }
            else
            {
                prime = 1;
            }
        }
    }
    if (prime == 0)
    {

        return 0;
    }
    else
    {

        return 1;
    }
}

void printPrime(int n)
{
    cout << "Prime numbers from 1 to " << n << " is: " << endl;
    for (int i = 2; i <= n; i++)
    {
        if (prime_num(i) == 1)
        {
            cout << i << "  ";
        }
    }
}
int main()
{
    printPrime(67);

    return 0;
}