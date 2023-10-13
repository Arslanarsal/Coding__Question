#include <bits/stdc++.h>
using namespace std;

/*
   Time Complexity: O(n^2)
   Space Complexity: O(n)
   where n is the length of the postfix expression.
*/

bool isoperant(char i)
{
    if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))
    {
        return true;
    }
    return false;
}

// Function to convert a postfix expression to infix notation.
string postToInfix(string postfix)
{
    int n = postfix.length();
    // Create a Stack of type string.
    stack<string> st;

    // Iterate over the postfix expression.
    for (int i = 0; i < n; i++)
    {
        // If the character is an operand (lowercase or uppercase letter),
        // push it to the stack as a string.
        if (isoperant(postfix[i]))
            st.push(string(1, postfix[i]));
        // If the character is an operator,
        // pop the top two elements from the stack and form a new string in infix notation.
        else
        {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            st.push('(' + v2 + postfix[i] + v1 + ')');
        }
    }

    // Return the final infix expression obtained from the stack.
    return st.top();
}

// Function to convert a prefix expression to infix notation.
string preToInfix(string prefix)
{
    int n = prefix.length();
    // Create a Stack of type string.
    stack<string> st;

    // Iterate over the postfix expression.
    for (int i = n-1; i >= 0; i--)
    {
        // If the character is an operand (lowercase or uppercase letter),
        // push it to the stack as a string.
        if (isoperant(prefix[i]))
            st.push(string(1, prefix[i]));
        // If the character is an operator,
        // pop the top two elements from the stack and form a new string in infix notation.
        else
        {
            string v1 = st.top();
            st.pop();
            string v2 = st.top();
            st.pop();
            st.push('(' + v1 + prefix[i] + v2 + ')');
        }
    }

    // Return the final infix expression obtained from the stack.
    return st.top();
}



int main()
{
    // string s = "ABC/DA-*+";
    // s = postToInfix(s);
    // cout << s<<endl;


    string a = "*-a/bc-/del";
    a = preToInfix(a);
    cout << a<<endl;

    return 0;
}