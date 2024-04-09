#include <bits/stdc++.h>
using namespace std;

stack<int> sortStack(stack<int> &s)
{
    if (s.size() < 2)
    {
        return s;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    if (num >= s.top())
    {
        s.push(num);
    }
    else
    {
        vector<int> temp;
        while (!s.empty() && num < s.top())
        {
            temp.push_back(s.top());
            s.pop();
        }
        s.push(num);
        while (!temp.empty())
        {
            s.push(temp[temp.size() - 1]);
            temp.pop_back();
        }
    }
    return s;
}

void reverseStack(stack<int> &stack, int k)
{
    if (stack.size() == 0)
    {
        stack.push(k);
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    stack.push(num);
}

void reverseStack(stack<int> &stack)
{
    if (stack.size() < 2)
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    reverseStack(stack, num);
}

int main()
{

    return 0;
}