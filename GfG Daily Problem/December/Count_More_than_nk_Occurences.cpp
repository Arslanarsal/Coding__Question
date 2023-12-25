#include <bits/stdc++.h>
using namespace std;

int countOccurence(int arr[], int n, int k)
{
    int apper = n / k;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int ans = 0;
    for (auto &&i : mp)
    {
        if (i.second >= apper)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{

    return 0;
}