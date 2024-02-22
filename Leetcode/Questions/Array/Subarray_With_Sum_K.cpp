#include <bits/stdc++.h>
using namespace std;

int f(int i, int k, vector<int> &a, int pre)
{
<<<<<<< HEAD
    if (k == 0)
    {
        return 0;
    }
    if (i == a.size() - 1)
    {
        return a[i] == k ? 1 : 0;
    }
=======

    if (k == 0 || i == a.size())
    {
        return 0;
    }
>>>>>>> 3ab346b50738de67ba7c20a1417a525a2e225960

    int notpick = f(i + 1, k, a, pre);
    int pick = INT_MIN;
    if ((pre == -1 || pre + 1 == i) && a[i] <= k)
    {
        pick = 1 + f(i + 1, k - a[i], a, i);
    }
    return max(pick, notpick);
}

int longestSubarrayWithSumK(vector<int> a, long long k)
{
    return f(0, k, a, -1);
}

int main()
{

    return 0;
}