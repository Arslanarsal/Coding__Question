#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    double v1 = (double)p1.second / p1.first;
    double v2 = (double)p2.second / p2.first;
    return v1 > v2;
}

double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), compare);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (w >= items[i].first)
        {
            ans += items[i].second;
            w -= items[i].first;
            continue;
        }
        double vw = (double)items[i].second / items[i].first;
        ans += vw * w;
        w = 0;
        break;
    }
    return ans;
}

int main()
{

    return 0;
}

