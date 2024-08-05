#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> arr(4, 0);
        int m = s.size();
        for (int i = 0; i < m; i++)
        {
            if (s[i] != '?')
            {
                arr[s[i] - 'A']++;
            }
        }
        long long ans = 0;
        for (int i = 0; i < 4; i++)
        {
            ans += min(n, arr[i]);
        }
        cout << ans<< "\n";
    }

    return 0;
}