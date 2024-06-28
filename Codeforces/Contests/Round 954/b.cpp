#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int arr[n][m];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> arr[i][j];
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int num = 0;
                if (i > 0)
                {
                    num = max(num, arr[i - 1][j]);
                }
                if (i < n - 1)
                {
                    num = max(num, arr[i + 1][j]);
                }
                if (j > 0)
                {
                    num = max(num, arr[i][j - 1]);
                }
                if (j < m - 1)
                {
                    num = max(num, arr[i][j + 1]);
                }
                if (arr[i][j] > num)
                {
                    arr[i][j] = num;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cout<< arr[i][j] <<" " ;
            }
            cout<<"\n";
        }
    }

    return 0;
}