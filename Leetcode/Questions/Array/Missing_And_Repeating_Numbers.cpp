#include <bits/stdc++.h>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    long long n = a.size();
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += a[i];
        s2 += (a[i] * 1LL * a[i]);
    }
    long long val1 = s - sn; // x-y
    long long val2 = s2 - s2n;

    val2 = val2 / val1; // x+y

    long long x = (val1 + val2) / 2;
    long long y = val2 - x;
    return {(int)x, (int)y};
}

int main()
{

    return 0;
}

vector<int> findTwoElement(vector<int> arr, int n)
{
    vector<int> result(2);

    // XOR all elements in the array and XOR with all numbers from 1 to N
    int xorResult = 0;
    for (int i = 0; i < n; ++i)
    {
        xorResult ^= arr[i];
        xorResult ^= (i + 1);
    }

    // Find the rightmost set bit in XOR result
    int rightmostSetBit = xorResult & -xorResult;

    // Split the array into two groups based on the rightmost set bit
    int group1 = 0, group2 = 0;
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] & rightmostSetBit)
            group1 ^= arr[i];
        else
            group2 ^= arr[i];

        int num = i + 1;
        if (num & rightmostSetBit)
            group1 ^= num;
        else
            group2 ^= num;
    }

    // Check which group contains the missing and duplicate numbers
    for (int i = 0; i < n; ++i)
    {
        if (arr[i] == group1)
        {
            result[0] = group1; // Duplicate number
            result[1] = group2; // Missing number
            break;
        }
        else if (arr[i] == group2)
        {
            result[0] = group2; // Duplicate number
            result[1] = group1; // Missing number
            break;
        }
    }

    return result;
}
