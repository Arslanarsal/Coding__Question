#include <bits/stdc++.h>
using namespace std;

int buyMaximumProducts(int n, int k, int price[])
{
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = {price[i], i + 1};
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {

        int pric = v[i].first;
        int day = v[i].second;
        if (k < pric)
        {
            break;
        }
        int max_stocks = min(k / pric, day);
        ans += max_stocks;
        k -= max_stocks * pric;
    }
    return ans;
}

int main()
{
    int v[] = {10, 7, 19};
    cout << buyMaximumProducts(3, 45, v);

    return 0;
}