// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

vector<int> leaders(vector<int> &nums)
{
    int n = nums.size();
    vector<int> result;
    int j;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (nums[i] <= nums[j])
            {
                break;
            }
        }
        if (j == n)
        {
            result.push_back(nums[i]);
        }
    }
    result.push_back(nums[n - 1]);

    return result;
}
int main()
{
    vector<int> nums = {2, 1, 5, 3, 1, 2};
    int n = nums.size();
    vector<int> result;
    result = leaders(nums);
    int nR = result.size();

    for (int i = 0; i < nR; i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}

// we can also use flag 
/*for (int i = 0; i < n - 1; i++)
    {int flag = 0
        for (j = i + 1; j < n; j++)
        {
            if (nums[i] <= nums[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            result.push_back(nums[i]);
        }
}  }
        result.push_back[n-1]*/