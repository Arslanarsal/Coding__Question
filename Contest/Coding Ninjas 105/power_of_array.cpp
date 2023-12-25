#include <bits/stdc++.h>
using namespace std;

int powerOfArray(int n, int k, vector<int> &a)
{
    vector<int> p = a;
    vector<int> q = a;
    p[0] = a[0];
    q[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        p[i] = p[i] + p[i - 1];
    }
    for (int i = n - 2; i >= 0; i--)
    {
        q[i] += q[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        cout << p[i] << "  ";
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << q[i] << "  ";
    }
    cout << endl;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int pp = 0;
        int qq = 0;
        if (i > 0)
        {
            pp = p[i - 1];
        }
        if (i < n - 1)
        {
            qq = q[i + 1];
        }
        int temp = pp + a[i] * k + qq;
        ans = max(ans, temp);
    }
    return ans;
}

int main()
{
    vector<int> v = {7, 9, 2, 3};
    cout << powerOfArray(4, 3, v);

    return 0;
}