#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> arr[i];
    }
    
    vector<int> dp(n + 1, -1);
    dp[0] = 0; 
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i >= arr[j] && dp[i - arr[j]] != -1)
            {
                dp[i] = max(dp[i], dp[i - arr[j]] + 1);
            }
        }
    }
    
    cout << dp[n] << "\n";

    return 0;
}
