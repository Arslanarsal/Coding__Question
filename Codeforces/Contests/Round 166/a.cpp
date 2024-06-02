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
        string str;
        cin >> str;
        int flage = true;
        int k = true;
        for (int i = 0; i < n - 1; i++)
        {
            if ((str[i] > str[i + 1]) || (!flage && str[i] >= 48 && str[i] <= 57) || (!isalpha(str[i]) && !isdigit(str[i])))
            {
                cout << "NO\n";
                k = false;
                break;
            }
            if (str[i] >= 97 && str[i] <= 122)
            {
                flage = false;
            }
        }
        if (k && ((n > 1 && str[n - 1] < str[n - 2]) || (!flage && str[n - 1] >= 48 && str[n - 1] <= 57)))
        {
            cout << "NO\n";
        }
        else if(k)
        {
            cout << "YES\n";
        }
    }

    return 0;
}