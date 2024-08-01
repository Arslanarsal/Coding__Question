#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<int> st;
        int n = s.size();
        string ans = "";
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                st.push(j);
            }
            else if (s[i] == ')')
            {
                int k = st.top();
                st.pop();
                reverse(ans.begin() + k, ans.end());
                        }
            else
            {
                ans += s[i];
                j++;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    sol.reverseParentheses("(u(love)i)");

    return 0;
}