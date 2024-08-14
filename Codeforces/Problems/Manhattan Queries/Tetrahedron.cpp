#include <iostream>
#include <vector>
#include <map>
using namespace std;

void dfs1(int u, int par, map<int, vector<int>> &mpp, vector<int> &in)
{
    for (int v : mpp[u])
    {
        if (v != par)
        {
            dfs1(v, u, mpp, in);
            in[u] = max(in[u], 1 + in[v]);
        }
    }
}

void dfs2(int u, int par, map<int, vector<int>> &mpp, vector<int> &out, vector<int> &in)
{
    int maxi1 = -1;
    int maxi2 = -1;

    for (int v : mpp[u])
    {
        if (v != par)
        {
            if (maxi1 <= in[v])
            {
                maxi2 = maxi1;
                maxi1 = in[v];
            }
            else if (maxi2 < in[v])
            {
                maxi2 = in[v];
            }
        }
    }

    for (int v : mpp[u])
    {
        if (par != v)
        {
            int l = maxi1;
            if (l == in[v])
                l = maxi2;
            out[v] = 1 + max(out[u], 1 + l);
            dfs2(v, u, mpp, out, in);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    map<int, vector<int>> mpp;
    for (int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        mpp[a].push_back(b);
        mpp[b].push_back(a);
    }

    vector<int> in(n, 0);
    dfs1(0, -1, mpp, in);

    vector<int> out(n, 0);
    dfs2(0, -1, mpp, out, in);

    for (int i = 0; i < n; i++)
        cout << max(in[i], out[i]) << " ";
}