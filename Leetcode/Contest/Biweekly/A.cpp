#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int winningPlayerCount(int n, vector<vector<int>> &pick)
    {
        sort(pick.begin(), pick.end());
        int total = 0;
        int m = pick.size();

        int i = 0;
        while (i < m)
        {
            vector<int> ans(10, 0);
            while (i < m - 1 && pick[i][0] == pick[i + 1][0])
            {
                ans[pick[i][1]]++;
                i++;
            }
            ans[pick[i][1]]++;
            bool flag = false;

            for (int j = 0; j < 10; j++)
            {
                if (ans[j] > pick[i][0])
                {
                    flag = true;
                }
            }
            total += flag;
            i++;
        }
        return total;
    }
};

int main()
{

    return 0;
}