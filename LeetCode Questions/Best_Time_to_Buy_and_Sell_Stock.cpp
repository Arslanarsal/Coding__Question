#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int BuyDay = 0, profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[BuyDay] > prices[i])
            {
                BuyDay = i;
            }
            if (profit < prices[i] - prices[BuyDay])
            {
                profit = prices[i] - prices[BuyDay];
            }
        }
        return profit;
    }
};

int main()
{
    Solution sol;
    vector<int> price = {7,6,4,3,1};
    cout << sol.maxProfit(price);
    return 0;
}