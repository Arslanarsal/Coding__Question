#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &relations, vector<int> &time)
    {
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> adj(n + 1);

        for (auto &rel : relations)
        {
            int ui = rel[0];
            int vi = rel[1];
            adj[ui].push_back(vi);
            indegree[vi]++;
        }

        queue<int> q;
        vector<int> totalTime(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                totalTime[i] = time[i - 1];
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (auto &&it : adj[node])
            {
                totalTime[it] = max(totalTime[it], totalTime[node] + time[it - 1]);
                indegree[it]--;

                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        return *max_element(totalTime.begin(), totalTime.end());
    }
};

int main()
{

    return 0;
}