#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O( n )
    Space Complexity: O( n )
    Where n is the size of the string 's'.
*/

string preToPost(string s)
{
    // Initializing a stack 'st'
    stack<string> st;

    // Reverse the string 's'
    reverse(s.begin(), s.end());

    // Initializing a array of operators
    vector<char> o = {'+', '-', '/', '*'};

    // Iterating over the string 's'
    for (int i = 0; i < (int)s.size(); ++i)
    {
        // Initialising a boolean variable 'isOp'
        bool isOp = false;

        // Iterating over the array 'o' to check
        // whether current character is 'operator' or not
        for (int j = 0; j < 4; ++j)
        {
            if (s[i] == o[j])
            {
                // We found an operator
                isOp = true;
            }
        }

        // Declare a string 'cur'
        string cur = "";
        // Append the current character to it
        cur += s[i];

        if (isOp == false)
        {
            // Push 'cur' in the stack 'st'
            st.push(cur);
        }
        else
        {
            // Declaring a string 's1'
            string s1 = st.top();
            // Pop the top element of the stack
            st.pop();

            // Declaring a string 's2'
            string s2 = st.top();
            // Pop the top element of the stack
            st.pop();

            // Push 's1 + s2 + cur' in the stack
            st.push(s1 + s2 + cur);
        }
    }

    // Return top of the stack
    return st.top();
}

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where n is the length of the input string.
*/

string postfixToPrefix(string s)
{
    stack<string> stk;

    // Length of expression
    int length = s.size();
    for (int i = 0; i < length; i++)
    {
        // Check if symbol is operator
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
        {
            // Pop two operands from stack
            string op1 = stk.top();
            stk.pop();
            string op2 = stk.top();
            stk.pop();

            string temp = s[i] + op2 + op1;

            // Push string temp back to stack
            stk.push(temp);
        }
        else
        {
            // Push the operand to the stack
            string add = "";
            add += s[i];
            stk.push(add);
        }
    }

    // Concatenate all strings in stack and return the answer
    string ans = "";

    while (stk.size() != 0)
    {
        ans += stk.top();
        stk.pop();
    }

    return ans;
}

int main()
{
    string s ="ED*CB+A/-";
    s = postfixToPrefix(s);
    cout<<s<<endl;

    return 0;
}