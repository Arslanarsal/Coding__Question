#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ans = 0;
    int n;
    cin >> n;
    while (n--)
    {
        string s1;
        cin >> s1;
        if (s1 == "++X" || s1 == "X++")
        {
            ans++;
        }
        else
        {
            ans--;
        }
    }
    cout << ans;

    return 0;
}