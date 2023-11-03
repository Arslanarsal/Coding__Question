#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto &&i : kArrays)
    {
        for (auto &&j : i)
        {
            pq.push(j);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<vector<int>> v1 = {{1, 2, 3, 4}, {2, 3, 4, 5, 7, 8}};
    vector<int> v = mergeKSortedArrays(v1, 2);
    for (auto &&i : v)
    {
        cout << i << " ";
    }

    return 0;
}