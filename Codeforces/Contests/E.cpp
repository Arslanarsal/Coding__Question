#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()
#define sowhat                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);
#define print(a)          \
    for (auto i : a)      \
    {                     \
        cout << i << ' '; \
    }                     \
    cout << endl;
#define in binary_search

int arr[200000 + 10];

void prec()
{
    for (int i = 1; i <= 200000; i++)
    {
        int steps = 0;
        int n = i;
        while (n > 0)
        {
            n /= 3;
            steps++;
        }
        arr[i] = steps;
    }
    // return steps;
}

int main()
{
    sowhat
    prec();
    int t;
    cin >> t;

    while (t--)
    {
        int l, r;
        cin >> l >> r;
        int total_steps = 0;
        for (int n = l + 1; n <= r; n++)
        {
            total_steps += arr[n];
        }
        int ss = arr[l] * 2;
        cout << total_steps + ss << endl;
    }

    return 0;
}
