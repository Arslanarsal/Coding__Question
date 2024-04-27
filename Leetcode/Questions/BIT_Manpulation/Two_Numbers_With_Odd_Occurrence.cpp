#include <bits/stdc++.h>
using namespace std;

vector<int> twoOddNum(vector<int> arr)
{
    int n = arr.size();
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    int buckit = (ans & (ans - 1)) & ans;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & buckit)
        {
            a = a ^ arr[i];
        }
        else
        {
            b = b ^ arr[i];
        }
    }
    if (a > b)
    {
        return {a, b};
    }
    return {b, a};
}

int main()
{

    return 0;
}