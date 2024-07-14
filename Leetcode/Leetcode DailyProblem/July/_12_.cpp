#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int left(string &s, int &x, int &y)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == 'a' && s[i + 1] == 'b')
            {
                ans += x;
                s[i] = '1';
                s[i + 1] = '1';
                i++;
            }
        }

        for (int i = n - 1; i > 0; i--)
        {
            if (s[i] == 'a' && s[i - 1] == 'b')
            {
                ans += y;
                s[i] = '1';
                s[i - 1] = '1';
                i++;
            }
        }
        return ans;
    }

    int right(string &s, int &x, int &y)
    {
        int n = s.size();
        int ans = 0;
        stack<char> st, st1;

        for (int i = n - 1; i > 0; i--)
        {
            if (!st.empty() && st.top() == 'a' && s[i] == 'b')
            {
                ans += y;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        while (!st.empty())
        {
            if (!st1.empty() && st1.top() == 'a' && st.top() == 'b')
            {
                ans += x;
                st1.pop();
            }
            else
            {
                st1.push(st.top());
                st.pop();
            }
        }
        return ans;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        // if (x > y)
        // {
        //     return left(s, x, y);
        // }
        return right(s, x, y);
    }
};

int main()
{

    Solution sol;
    string s = "cdbcbbaaabab";
    int x = 4;
    int y = 5;
    sol.maximumGain(s, x, y);

    return 0;
}