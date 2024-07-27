#include <bits/stdc++.h>
using namespace std;
int k;

inline bool cmp(int a, int b)
{
    if (a % k == b % k)
    {
        return a < b;
    }
    return (a % k) < (b % k);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end(), cmp);
        long long ans = 0;
        bool flage = false;
        for (int i = 0; i < n; i++)
        {
            int j = i;

            while (j + 1 < n && arr[j] % k == arr[j + 1] % k)
            {
                j++;
            }
            if ((j - i + 1) % 2)
            {
                if (flage)
                {
                    ans = -1;
                    break;
                }
                long long prefix[n], suffex[n];
                for (int l = 0; l < n; l++)
                {
                    prefix[l] = 0;
                    suffex[l] = 0;
                }
                for (int l = i + 2; l <= j; l += 2)
                {
                    prefix[l] = prefix[l - 2] + (arr[l - 1] - arr[l - 2]) / k;
                }
                for (int l = j - 2; l >= i; l -= 2)
                {
                    suffex[l] = suffex[l + 2] + (arr[l + 2] - arr[l + 1]) / k;
                }

                long long temp = LLONG_MAX;
                for (int l = i; l <= j; l += 2)
                {
                    temp = min(temp, (prefix[l] + suffex[l]));
                }
                ans += temp;
                flage = true;
            }
            else
            {
                for (int l = i; l < j; l += 2)
                {
                    ans += (arr[l + 1] - arr[l]) / k;
                }
            }
            i = j;
        }
        cout << ans << "\n";
    }
    return 0;
}