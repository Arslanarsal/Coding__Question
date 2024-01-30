#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        int n = tokens.size();
        stack<int> st;
        int a, b;
        for (int i = 0; i < n; i++)
        {
            string temp = tokens[i];
            if (temp == "+" || temp == "-" || temp == "*" || temp == "/")
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                if (temp == "+")
                {
                    st.push(a + b);
                }
                else if (temp == "-")
                {
                    st.push(a - b);
                }
                else if (temp == "*")
                {
                    st.push(a * b);
                }
                else
                {
                    st.push(a / b);
                }
            }
            else
            {
               
                st.push(stoi(temp));
            }
        }
        return st.top();
    }
};

int main()
{
    vector<string> v = {"2", "1", "+", "3", "*"};
    Solution sol;
    cout << sol.evalRPN(v);

    return 0;
}