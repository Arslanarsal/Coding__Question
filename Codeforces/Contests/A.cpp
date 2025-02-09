#include <bits/stdc++.h>

using namespace std;

int t, n, q, m, x;

int32_t main()
{

    t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cin >> m;
        if ((m - arr[0]) < arr[0])
        {
            arr[0] = m - arr[0];
        }

        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            int k = (m - arr[i]);
            if (k < arr[i] && k >= arr[i - 1])
            {
                arr[i] = k;
            }

            if (arr[i] < arr[i - 1])
            {
                flag = true;
                break;
            }
        }

        if (flag)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }

    return 0;
}