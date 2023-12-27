#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int n = prices.size();
        int firstmin = min(prices[0], prices[1]);
        int secondmin = max(prices[0], prices[1]);
        for (int i = 0; i < n; i++)
        {
            if (prices[i] < secondmin && prices[i] >= firstmin)
            {
                secondmin = prices[i];
            }
            else if (prices[i] < secondmin && prices[i] < firstmin)
            {
                secondmin = firstmin;
                firstmin = prices[i];
            }
        }
        if (money - (firstmin + secondmin) >= 0)
        {
            return money - (firstmin + secondmin);
        }
        return money;
    }
};

int main()
{

    return 0;
}