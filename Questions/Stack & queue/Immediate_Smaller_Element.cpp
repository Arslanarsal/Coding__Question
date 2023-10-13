#include <bits/stdc++.h>
using namespace std;

void immediateSmaller(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] > a[i + 1])

            a[i] = a[i + 1];
        else
            a[i] = -1;
    }
    a[n-1] = -1;
}

int main()
{
    vector<int> v = {1 ,2 ,3, 4};
    immediateSmaller(v);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}