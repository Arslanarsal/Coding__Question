#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {

        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int num = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i + 1] <= arr[i])
            {
                num++;
            }
        }
        if (arr[n - 1] < arr[0])
        {
            num++;
        }
        if (num > 1)
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
        }
    }
    return 0;
}