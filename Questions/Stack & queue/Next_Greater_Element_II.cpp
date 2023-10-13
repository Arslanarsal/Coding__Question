#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the length of the array 'a'.
*/

vector<int> nextGreaterElementII(vector<int> &a)
{
    int n = a.size();

    // Initialize an array 'answer' of size 'n' with -1,
    // to store the Next Greater Element for each element.
    vector<int> answer(n, -1);

    // Initialize an empty stack 'st'
    // to keep the track of the next greater element.
    stack<int> st;

    for (int i = 0; i < 2 * n; i++)
    {

        while (st.size() != 0 && a[st.top()] < a[i % n])
        {
            answer[st.top()] = a[i % n];
            st.pop();
        }

        if (i < n)
            st.push(i % n);
    }

    // Return 'answer' as the answer to the problem.
    return answer;
}

int main()
{
    vector<int> v = {2, 3, 11, 2, 3, 4};
    v = nextGreaterElementII(v);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}