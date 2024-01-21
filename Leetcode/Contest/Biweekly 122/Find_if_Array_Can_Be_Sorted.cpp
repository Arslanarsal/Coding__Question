#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &arr)
    {
        int n = arr.size();
        int i, key, j;
        for (i = 1; i < n; i++)
        {
            key = arr[i];
            j = i - 1;

            while (j >= 0 && arr[j] > key)
            {
                if (__builtin_popcount(key) != __builtin_popcount(arr[j]))
                {
                    return false;
                }

                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        return true;
    }
};

int main()
{

    return 0;
}