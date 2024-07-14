#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int ans = 0;
        int n = logs.size();
        for (int i = 0; i < n; i++)
        {
            if (logs[i][0] != '../' && logs[i][0] != './')
            {
                ans++;
            }
            else if (logs[i] == "../" && ans)
            {
                ans--;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}