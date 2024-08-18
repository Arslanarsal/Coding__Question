#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n, k;
vector<int> arr;

int32_t main()
{
    cin >> n >> k;
    arr.resize(k);
    for (int i = 0; i < k; i++)
    {
        cin >> arr[i];
    }
    vector<int> v(k + 1, 0);
    for (int i = 1; i < (1 << k); i++)
    {
        int count = 0;
        int temp = n;
        for (int j = 0; j < k; j++)
        {
            if ((1 << j) & i)
            {
                temp = temp / arr[j];
                count++;
            }
        }
        v[count] += temp;
    }
    int ans = 0;
    for (int i = 1; i < k + 1; i++)
    {
        if (i & 1)
        {
            ans += v[i];
        }
        else
        {
            ans -= v[i];
        }
    }
    cout << ans << "\n";

    return 0;
}