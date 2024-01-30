#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countKeyChanges(string s)
    {
        int n = s.length();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] < 'a')
            {
                s[i] = char(s[i] | ' ');
            }
            if (s[i+1] < 'a')
            {
                s[i+1] = char(s[i+1] | ' ');
            }
            if (s[i+1] != s[i])
            {
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
    cout<<sqrt(25);

    return 0;
}