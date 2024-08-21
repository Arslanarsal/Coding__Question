#include <bits/stdc++.h>
using namespace std;

#define int long long int
vector<vector<int>> arr;
vector<int> dp;
int n;


int findNext(int i)
{
    int lo = i + 1, hi = n - 1, next = n;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid][0] > arr[i][1])
        {
            next = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return next;
}

int32_t main()
{
    cin >> n;
    arr.resize(n, vector<int>(3));
    dp.resize(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    // Sort intervals by end time
    sort(arr.begin(), arr.end());

    // Bottom-up DP approach
    for (int i = n - 1; i >= 0; i--)
    {
        int next = findNext(i);
        dp[i] = max(arr[i][2] + dp[next], dp[i + 1]);
    }

    cout << dp[0] << "\n"; 

    return 0;
}
