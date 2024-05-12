#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    typedef vector<double> v;
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<v, vector<v>, greater<v>> pq;
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            pq.push({(1.0 * arr[i]) / arr[n - 1], (double)i, (double)n - 1});
        }
        int m = 1;
        while (m < k)
        {
            v vec = pq.top();
            pq.pop();
            int i = vec[1];
            int j = vec[2] - 1;
            pq.push({(1.0 * arr[i]) / arr[j], (double)i, (double)j});
            m++;
        }
        v vec = pq.top();
        int i = vec[1];
        int j = vec[2];
        return {arr[i], arr[j]};
    }
};

int main()
{

    return 0;
}