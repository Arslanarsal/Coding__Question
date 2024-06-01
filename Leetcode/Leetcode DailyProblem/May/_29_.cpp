#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSteps(string s)
    {
        int ans = 0;
        s = '0' + s;
        int n = s.size();
        int i = n - 1;
        while (i > 0)
        {
            while (i > 0 && s[i] == '0')
            {
                ans++;
                i--;
            }
            if (i == 1 && s[i] == '1')
            {
                break;
            }
            int j = i;
            while (j > 0 && s[j] == '1')
            {
                s[j] = '0';
                j--;
            }
            if (j < i)
            {
                ans++;
            }
            s[j] = '1';
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    sol.numSteps("10");

    return 0;
}