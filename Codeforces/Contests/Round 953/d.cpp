#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        v.resize(n);
        int largeindx = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (i == 0)
            {
                largeindx = i;
                v[0] += c;
            }
            if (v[largeindx] < v[i])
            {
                largeindx = i;
            }
        }
        long long sum = 0;
        for (int i = 0; i < largeindx; i++)
        {
            if (sum + v[i] >= v[largeindx])
            {
                sum += v[i];
                cout << i << " ";
            }
            else
            {
                sum += v[i];
                cout << i + 1 << " ";
            }
        }
        cout << 0 << " ";
        for (int i = largeindx + 1; i < n; i++)
        {
            cout << i << " ";
        }

        cout << "\n";
    }

    return 0;
}