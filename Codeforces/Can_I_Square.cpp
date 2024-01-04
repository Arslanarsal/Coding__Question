#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define ios                          \
    os_base::sync_with_stdio(false); \
    in.tie(0);                       \
    out.tie(0);
const ll mod = 1e9 + 7;

int main()
{
#ifndef ONLINE_JUDGE
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            sum += temp;
        }
        ll root = sqrt(sum);
        if (root * root == sum)
        {
            cout << "yes\n";
        }
        else
        {
            cout << "No\n";
        }
    }
    return 0;
}