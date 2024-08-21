#include <bits/stdc++.h>
using namespace std;
#define int long long int
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, int> mp;
        int maxele = 0;
        for (auto &&it : arr)
        {
            mp[it]++;
            maxele = max(maxele, mp[it]);
        }
        cout << n - maxele << "\n";
    }

    return 0;
}
