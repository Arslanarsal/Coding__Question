#include "bits/stdc++.h"
using namespace std;

/*
    Time Complexity : O(n)
    Space Complexity : O(n)

    where n is the length of the expression.
*/

bool isOperator(char ch)
{
    if (ch - 'a' >= 0 && ch - 'a' <= 25)
    {
        return true;
    }
    if (ch - 'A' >= 0 && ch - 'Z' <= 25)
    {
        return true;
    }
    else if (ch - '0' >= 0 && ch - '0' <= 9)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string infixToPostfix(string exp)
{
    string ans = "";
    stack<char> s;

    // Precedence of the operators
    unordered_map<char, int> precedence;

    precedence['^'] = 3;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['('] = 0;
    precedence[')'] = 0;

    for (int i = 0; i < exp.length(); i++)
    {
        if (isOperator(exp[i]))
        {
            ans += exp[i];
        }
        else if (exp[i] == ')')
        {

            // Remove till the last opening
            while (s.top() != '(')
            {
                ans += s.top();
                s.pop();
            }
            s.pop();
        }
        else if (exp[i] == '(')
        {
            s.push(exp[i]);
        }
        else
        {

            // Remove lower precedence operators
            while (s.size() && precedence[s.top()] >= precedence[exp[i]])
            {
                ans += s.top();
                s.pop();
            }
            s.push(exp[i]);
        }
    }
    while (s.size())
    {
        ans += s.top();
        s.pop();
    }
    return ans;
}
int main()
{
    string a = "(A/(B+C))";
    a = infixToPostfix(a);
    cout << a;

    return 0;
}