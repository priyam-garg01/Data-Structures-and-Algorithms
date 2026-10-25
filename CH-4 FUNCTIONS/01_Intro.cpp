#include <iostream>
using namespace std;

int printHello() // Function definition
{
    cout << "Hello" << endl;
    return 8;
}

float sum(float a, float b) // a, b are parameters
// while the input values are arguments
// (literals) whose value is constant
{
    return a + b;
}

float min_numb(float a, float b)
{
    if (a < b)
    {
        return a;
    }
    else if (a > b)
    {
        return b;
    }
    else
        cout << "Numbers are equal" << endl;
    return 0;
}
int sum_of_n(int n)
{
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "Sum of numbers from 1 to " << n << " : " << sum << endl;
    return sum;
}
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

int main()
{
    printHello(); // Function call

    cout << printHello() << endl;

    int val = printHello();
    cout << val << endl;

    cout << sum(4, 90) << endl;

    cout << min_numb(56, 56) << endl;

    sum_of_n(5);

    cout << factorial(7);
    return 0;
}