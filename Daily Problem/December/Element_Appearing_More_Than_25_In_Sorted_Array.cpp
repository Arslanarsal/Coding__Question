#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
            return arr[0];
        int max = arr[0];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (arr[i] == max)
            {
                cnt++;
                if (cnt > n / 4)
                    return max;
            }
            else
            {
                max = arr[i];
                cnt = 1;
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}