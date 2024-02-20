#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices)
{
    int n = prices.size();
    int mini = prices[0];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        ans = max(ans, cost);
        mini = min(mini, prices[i]);
    }
    return ans;
}

int main()
{

    return 0;
}