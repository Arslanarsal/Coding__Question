#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> ans(n, 0);
        int m = trust.size();
        int a = 0;
        int j = 0;
        for (int i = 0; i < m; i++)
        {
            ans[trust[i][1]]++;
        }
        for (int i = 0; i <= n; i++)
        {
            if (ans[i] == n - 1)
            {
                return ans[i];
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}