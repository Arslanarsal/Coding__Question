#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity: O(N + M)
    Space Complexity: O(N)

    where 'N' is the number of vertices and
    'M' is the number of edges in the graph.
*/

string canFinish(vector<vector<int>> &prerequisites, int n, int m)
{
    //	Create a graph.
    vector<vector<int>> graph(n + 1, vector<int>());

    //	Add the edges.
    for (int i = 0; i < m; i++)
    {
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    //	To store the indegree of the vertices.
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        indegree[prerequisites[i][0]]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    int visited = 0;

    while (q.size() != 0)
    {
        //	Get the front element from the queue.
        int vertex = q.front();
        q.pop();

        visited++;

        for (int adjVertex : graph[vertex])
        {
            indegree[adjVertex]--;

            if (indegree[adjVertex] == 0)
            {
                q.push(adjVertex);
            }
        }
    }

    if (visited == n)
    {
        return "Yes";
    }

    return "No";
}

int main()
{

    return 0;
}



vector<int> findSchedule(int n, vector<pair<int, int>> &prerequisites)
{
    //	Create a graph.
    int m = prerequisites.size();
    vector<vector<int>> graph(n + 1, vector<int>());

    //	Add the edges.
    for (int i = 0; i < m; i++)
    {
        graph[prerequisites[i].second].push_back(prerequisites[i].first);
    }

    //	To store the indegree of the vertices.
    vector<int> indegree(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        indegree[prerequisites[i].first]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> ans;

    while (q.size() != 0)
    {
        //	Get the front element from the queue.
        int vertex = q.front();
        q.pop();

        ans.push_back(vertex);

        for (int adjVertex : graph[vertex])
        {
            indegree[adjVertex]--;

            if (indegree[adjVertex] == 0)
            {
                q.push(adjVertex);
            }
        }
    }

    if (ans.size() == n)
    {
        return ans;
    }

    return {};
}
