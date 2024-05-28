#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int find(int A[], int x)
    {
        if (A[x] == x)
        {
            return x;
        }
        return A[x] = find(A, A[x]);
    }

public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
        {
            return -1;
        }

        int parent[n];
        int size[n] ;
        int num = 0;
        for (int i = 0; i < n; i++)
        {
            size[i] =1;
            parent[i] = i;
        }
        for (auto &&it : connections)
        {
            int pu = find(parent, it[0]);
            int pv = find(parent, it[1]);

            if (size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
            else if (size[pu] > size[pv])
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (parent[i] == i)
            {
                ans++;
            }
        }
        return ans - 1;
    }
};

int main()
{

    return 0;
}