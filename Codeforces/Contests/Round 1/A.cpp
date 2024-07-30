#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.size();
        int i = 0;
        while (i < n - 1 && s[i] != s[i + 1])
        {
            i++;
        }

        if (s[i] == 'z')
        {
            char ch = 'a';
            s.insert(s.begin() + i + 1, ch);
        }
        else
        {
            s.insert(s.begin() + i + 1, s[i] + 1);
        }
        cout << s << "\n";
    }

    return 0;
}