#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        priority_queue<int> pq;
        vector<pair<int, int>> v;
        int n = profits.size();
        for (int i = 0; i < n; i++)
        {
            v.push_back({capital[i], profits[i]});
        }
        sort(v.begin(), v.end());
        int ans = w;
        int i = 0;
        while (i < n)
        {
            while (i < n && ans >= v[i].first)
            {
                pq.push(v[i].second);
                i++;
            }
            if (!pq.empty() && k)
            {
                ans += pq.top();
                pq.pop();
            }
            else
            {
                break;
            }
            k--;
        }
        while (!pq.empty() && k)
        {
            ans += pq.top();
            pq.pop();
            k--;
        }

        return ans;
    }
};

int main()
{

    return 0;
}