// WAF to print all the unique values in an array

#include <iostream>
using namespace std;

int main()
{
    int num[] = {5677, 782, 1, 1, 5677, 782, 37383, -23};

    for (int i = 0; i < 8; i++)
    {
        bool isUnique = true;

        for (int j = 0; j < i; j++)
        {
            if (num[i] == num[j])
            {
                isUnique = false;
                break;
            }
        }
        if (isUnique)
        {
            cout << num[i] << endl;
        }
    }

    return 0;
}