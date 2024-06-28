#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<int> indegree(n, 0);
        for (auto &&it : roads)
        {
            indegree[it[0]]++;
            indegree[it[1]]++;
        }
        sort(indegree.begin(), indegree.end(), [&](int &a, int &b)
             { return a > b; });
        long long ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            ans += (indegree[i] * 1LL * (n - i));
        }
        ans += indegree[n - 1];
        return ans;
    }
};

int main()
{

    return 0;
}