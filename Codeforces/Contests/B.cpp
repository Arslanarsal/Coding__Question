#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> arr;
        ll even = 0, maxodd = -1, maxeven = -1;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x & 1)
            {
                maxodd = max(x, maxodd);
            }
            else
            {
                arr.push_back(x);
                even++;
                maxeven = max(x, maxeven);
            }
        }

        if (maxodd == -1 || even == 0)
        {
            cout << 0 << "\n";
            continue;
        }
        if (maxodd > maxeven)
        {
            cout << even << "\n";
        }
        else
        {
            sort(arr.begin(), arr.end());
            int m = arr.size();
            bool flag = false;
            for (int i = 0; i < m; i++)
            {
                if (maxodd < arr[i])
                {
                    flag = true;
                    break;
                }
                maxodd += arr[i];
            }
            cout << even + flag << "\n";
        }
    }

    return 0;
}