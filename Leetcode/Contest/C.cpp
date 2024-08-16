#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> prefix(n, 0);
        prefix[0] = s[0] == '1';
        for (int i = 1; i < n; i++)
        {
            prefix[i] += prefix[i - 1] + s[i] == '1';
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int one = prefix[j];
                if (i != 0)
                {
                    one -= prefix[i - 1];
                }
                int zero = (j - i + 1) - one;

                if ((zero * zero) > one)
                {
                    j += (zero * zero) - one - 1;
                }

                if ((zero * zero) <= one)
                {
                    ans++;

                    if ((zero * zero) < one)
                    {
                        int diff = (sqrt(one)) - zero;
                        int next = j + diff;
                        if (next >= n)
                        {
                            ans += (n - j - 1);
                        }
                        else
                        {
                            ans += diff;
                        }
                        j = next;
                    }
                }
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}