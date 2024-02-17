#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);

    string n;
    cin >> n;
    int t = n.size();
    int ans = 1;
    int temp = 1;
    for (int i = 1; i < t; i++)
    {
        if (n[i] != n[i - 1])
        {
            temp = 0;
        }
        temp++;
        ans = max(ans, temp);
    }
    cout << ans;

    return 0;
}