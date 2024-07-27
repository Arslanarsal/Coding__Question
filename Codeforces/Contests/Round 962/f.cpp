// #include <bits/stdc++.h>
// using namespace std;

// #define int long long

// using ll = long long;
// using pii = pair<int, int>;

// const int N = 2e5 + 20, inf = 1e9 + 20;
// int n, k, a[N], b[N];

// inline pii get(int lb)
// {
//     int tot_num = 0, tot_sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         int diff = max(0ll, a[i] - lb);
//         int count = diff / b[i] + (a[i] >= lb);
//         tot_num += count;

//         int sum = a[i] * count - (count - 1) * count / 2 * b[i];
//         tot_sum += sum;
//     }

//     if (tot_num > k)
//     {
//         tot_sum -= (tot_num - k) * lb;
//     }

//     return pii(tot_num, tot_sum);
// }

// int32_t main()
// {

//     int t;
//     cin >> t;

//     while (t--)
//     {
//         cin >> n >> k;
//         for (int i = 0; i < n; i++)
//             cin >> a[i];
//         for (int i = 0; i < n; i++)
//             cin >> b[i];

//         int low = 0, high = inf;

//         while (high - low > 1)
//         {
//             int mid = (low + high) / 2;

//             if (get(mid).first >= k)
//                 low = mid;
//             else
//                 high = mid;
//         }

//         cout << get(low).second << '\n';
//     }
// }

#include <bits/stdc++.h>
using namespace std;
const long long N = 2e5 + 20;
long long n, k, a[N], b[N];

pair<long long, long long> solve(long long bl)
{
    long long tot_num = 0, tot_sum = 0;
    for (int i = 0; i < n; i++)
    {
        // if (a[i] < bl)
        // {
        //     continue;
        // }

        long long diff = max(0LL, a[i] - bl);

        long long count = diff / b[i] + (a[i] >= bl);

        tot_num += count;

        long long sum = a[i] * count - (count - 1) * count / 2 * b[i];

        tot_sum += sum;
    }

    if (tot_num > k)
    {
        tot_sum -= (tot_num - k) * bl;
    }

    return {tot_num, tot_sum};
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;

        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        long long low = 0, high = 1e9 + 20;
        while (high - low > 1)
        {
            long long mid = (high + low) / 2;

            if (solve(mid).first >= k)
            {
                low = mid;
            }
            else
            {
                high = mid;
            }
        }

        cout << solve(low).second << "\n";
    }

    return 0;
}