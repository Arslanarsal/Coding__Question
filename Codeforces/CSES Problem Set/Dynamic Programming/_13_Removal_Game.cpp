#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define INF LLONG_MAX

int n;
vector<int> arr;
vector<vector<int>> dp;

int solve(int left, int right)
{
    if (left > right)
    {
        return 0;
    }


    int &d = dp[left][right];
    if (d != -1)
    {
        return d;
    }

    int ans = LLONG_MIN;
    int ret = min(solve(left + 2, right), solve(left + 1, right - 1));
    ans = max(ans, arr[left] + ret);

    ret = min(solve(left, right - 2), solve(left + 1, right - 1));
    ans = max(ans, arr[right] + ret);
    return d = ans;
}

int32_t main()
{
    cin >> n;
    arr.resize(n);
    dp.resize(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << solve(0, n - 1) << endl;

    return 0;
}
