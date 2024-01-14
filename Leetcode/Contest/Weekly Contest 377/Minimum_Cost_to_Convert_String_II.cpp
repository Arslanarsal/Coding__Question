#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        
        unordered_map<string, int> lebal;
        for (auto &&i : original)
        {
            if (!lebal.count(i))
            {
                lebal[i] = lebal.size();
            }
        }

        for (auto &&i : changed)
        {
            if (!lebal.count(i))
            {
                lebal[i] = lebal.size();
            }
        }

        int n = lebal.size();

        vector<vector<long>> dis(n, vector<long>(n, INT_MAX));

        for (int i = 0; i < cost.size(); i++)
        {
            int x = lebal[original[i]];
            int y = lebal[changed[i]];
            dis[x][y] = min(dis[x][y], (long)cost[i]);
        }

        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                if (dis[i][k] < INT_MAX)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (dis[k][j] < INT_MAX)
                        {
                            dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                        }
                    }
                }
            }
        }




    }
};

int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<string> orignal = {"a", "b", "c", "c", "e", "d"};
    vector<string> changed = {"b", "c", "b", "e", "b", "e"};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    Solution sol;
    sol.minimumCost(source, target, orignal, changed, cost);

    return 0;
}