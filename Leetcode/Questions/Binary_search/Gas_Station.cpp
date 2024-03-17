#include <bits/stdc++.h>
using namespace std;

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howmany(n - 1, 0);
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    for (int i = 1; i <= k; i++)
    {
        auto it = pq.top();
        pq.pop();
        int ind = it.second;
        howmany[ind]++;
        long double diff = arr[ind + 1] - arr[ind];
        long double secdiff = diff / (long double)(howmany[ind] + 1);
        pq.push({secdiff, ind});
    }
    return pq.top().first;
}

int main()
{

    return 0;
}