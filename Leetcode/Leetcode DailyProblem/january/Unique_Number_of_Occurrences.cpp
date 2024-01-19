#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int n = 1000;
        vector<int> ar(2 * n + 1, 0);

        for (auto &&el : arr)
        {
            ar[n + el]++;
        }
        sort(ar.begin(), ar.end());
        for (int i = 0; i < 2 * n; i++)
        {
            if (ar[i] != 0 && ar[i] == ar[i + 1])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}