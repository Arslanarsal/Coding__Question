#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N)
    Space Complexity:O(1)

    Where 'N' is the no. of operations performed.
*/

class minStack
{
    stack<long long> st;
    long long min;

public:
    // Constructor
    minStack() {}

    // Function to add another element equal to num at the top of stack.
    void push(int val)
    {
        if (st.empty())
        {
            st.push(val);
            min = val;
        }
        else
        {
            if (val < min)
            {
                st.push(2 * 1LL * val - min);
                min = val;
            }
            else
            {
                st.push(val);
            }
        }
    }

    // Function to remove the top element of the stack.
    int pop()
    {
        if (st.empty())
        {
            return -1;
        }
        long long val = st.top();
        st.pop();
        if (val < min)
        {
            int ans = min;
            min = 2 * min - val;
            return ans;
        }
        return val;
    }

    // Function to return the top element of stack if it is present. Otherwise return -1.
    int top()
    {
        if (st.empty())
        {
            return -1;
        }
        long long val = st.top();
        if (val < min)
        {
            return min;
        }
        return val;
    }

    // Function to return minimum element of stack if it is present. Otherwise return -1.
    int getMin()
    {
        if (st.empty())
        {
            return -1;
        }
        return min;
    }
};
int main()
{

    return 0;
}
