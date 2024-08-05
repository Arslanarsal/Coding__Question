#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
vector<int> divisor(N, 0);

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j * j <= arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                if (j * j != arr[i])
                {
                    divisor[(arr[i] / j)]++;
                }

                divisor[j]++;
            }
        }
    }
    int ans = 1;

    for (int i = 2; i < N; i++)
    {
        if (divisor[i] > 1)
        {
            ans = i;
        }
    }
    cout << ans << "\n";
    return 0;
}