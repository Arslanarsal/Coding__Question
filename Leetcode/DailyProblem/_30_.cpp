#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(string s)
    {
        int a = -1;
        int b = -1;
        int n = s.size();
        int i = 0;
        while (i < n && s[i] == 'a')
        {
            i++;
        }
        if (i != n)
        {
            b = i;
        }
        i = n - 1;
        while (i >= 0 && s[i] == 'b')
        {
            i--;
        }
        if (i != -1)
        {
            a = i;
        }
        if (a == -1 || b == -1 || a < b)
        {
            return 0;
        }
        int num1 = 0;
        int num2 = 0;
        i = b;
        // cout << a << " " << b << "\n";
        while (i < a)
        {
            if (s[i] == 'b')
            {
                num1++;
            }
            i++;
        }

        i = a;
        while (i > b)
        {
            if (s[i] == 'a')
            {
                num2++;
            }
            i--;
        }
        return min(num1, num2);
    }
};

int main()
{
    Solution sol;
    string s = "bbaaaaabb";
    sol.minimumDeletions(s);

    return 0;
}