#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();
        priority_queue<pair<long double, pair<long double, long double>>> pq;
        for (int i = 1; i < n; i++)
        {
            long double dist = stations[i] - stations[i - 1];
            pq.push({dist, {dist, 1}});
        }

        while (k--)
        {
            long double dist = pq.top().second.first;
            long double num = pq.top().second.second;
            pq.pop();
            num++;
            long double newdist = dist / num;
            pq.push({newdist, {dist, num}});
        }
        long double result = pq.top().first;
        return round(result * 100.0) / 100.0;
    }
};

int main()
{

    return 0;
}