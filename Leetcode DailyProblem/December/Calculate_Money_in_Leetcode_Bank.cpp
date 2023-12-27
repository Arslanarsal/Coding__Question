#include <bits/stdc++.h>
using namespace std;

int totalMoney(int n)
{
    int ans = 0;
    int week = 1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (i < n && j < 7)
        {
            ans += j + week;
            i++;
            j++;
        }
        i--;
        week++;
    }
    return ans;
}

class Solution
{
public:
    int totalMoney(int n)
    {
        int remainingDays = n % 7, fullWeeks = n / 7;

        int res = (fullWeeks * 28 + (fullWeeks - 1) * fullWeeks / 2 * 7) + ((remainingDays + 1 + 2 * fullWeeks) * remainingDays / 2);

        return res;
    }
};

int main()
{
    cout << totalMoney(20);

    return 0;
}