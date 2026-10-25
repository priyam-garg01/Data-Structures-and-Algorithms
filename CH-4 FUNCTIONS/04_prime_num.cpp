#include <iostream>

using namespace std;

void prime_num(int n)
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
        cout << n << " is not prime number" << endl;
    }
    else 
        cout << n << " is a prime number" << endl;
}
int main()
{
    prime_num(87);

    return 0;
}