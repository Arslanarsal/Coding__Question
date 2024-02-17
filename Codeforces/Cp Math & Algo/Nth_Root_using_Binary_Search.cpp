#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-6;

double multiplay(double mid, int n)
{
    double ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
};

int main()
{
    double num; // Number
    cin >> num;
    int n;
    cin >> n; // Number of times to multiply the number by itself
    double low = 1, high = num, mid;
    while (high - low > eps)
    {
        mid = (high + low) / 2;
        if (multiplay(mid, n) < num)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << high;
    return 0;
}