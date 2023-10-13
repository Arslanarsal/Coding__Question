#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where 'n' is the number of elements in the array.
*/

vector<int> nextGreaterElement1(vector<int> &arr, int n)
{
    // Create a vetor to store next Greater elements
    vector<int> ans(n);

    // Stack, to keep track of next greater element
    stack<int> s;

    // Traverse in reverse fashion in the array
    for (int i = n - 1; i >= 0; i--)
    {
        // If current element is greater than or equal to stack's top
        // element, we can pop it since now it will never get picked
        // as the next greater element
        while (!s.empty() && arr[i] >= s.top())
        {
            s.pop();
        }

        // If stack is not empty, stack's top element is
        // the next greater element, else there is none
        if (!s.empty())
        {
            ans[i] = s.top();
        }
        else
        {
            ans[i] = -1;
        }

        // Push current element onto stack
        s.push(arr[i]);
    }

    // return final answer vector
    return ans;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> Umap;
    vector<int> v;
    stack<int> st;

    int n = nums2.size() - 1;
    for (int i = n; i >= 0; i--)
    {
        while (!st.empty() && nums2[i] >= st.top())
        {
            st.pop();
        }
        if (st.empty())
        {
            Umap[nums2[i]] = -1;
        }
        else
        {
            Umap[nums2[i]] = st.top();
        }
        st.push(nums2[i]);
    }
    n = nums1.size();
    for (int i = 0; i < n; i++)
    {
        v.push_back(Umap[nums1[i]]);
    }
    return v;
}

int main()
{

    vector<int> v = {2, 4};
    vector<int> v1 = {1, 2, 3, 4};
    // v = nextGreaterElement1(v, 4);
    v = nextGreaterElement(v, v1);

    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}