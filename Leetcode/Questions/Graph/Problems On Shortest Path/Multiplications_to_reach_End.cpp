#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumMultiplications(vector<int> &arr, int start, int end)
    {
        if (start == end)
        {
            return 0;
        }
        int mod = 1e5;
        int n = arr.size();
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(mod, INT_MAX);
        dist[start] = 0;
        while (!q.empty())
        {
            int node = q.front().first;
            int step = q.front().second;
            q.pop();
            for (auto &&it : arr)
            {
                int num = (it * node) % mod;
                if (num == end)
                {
                    return step + 1;
                }

                if (step + 1 < dist[num])
                {
                    dist[num] = step + 1;
                    q.push({num, step + 1});
                }
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}