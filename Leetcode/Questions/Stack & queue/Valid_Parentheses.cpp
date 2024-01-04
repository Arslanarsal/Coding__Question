#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the length of the string.
*/

bool isValid(string s)
{
    stack<char> st;
    for (char c : s)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            st.push(c);
        }
        else
        {
            if (st.empty())
            {
                return false;
            }
            if ((c == ')' && st.top() != '(') ||
                (c == ']' && st.top() != '[') ||
                (c == '}' && st.top() != '{'))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{

    return 0;
}