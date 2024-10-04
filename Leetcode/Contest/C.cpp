#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    long long maximumTotalSum(vector<int> &maximumHeight)
    {
        priority_queue<int> pq(maximumHeight.begin(), maximumHeight.end());
        long long sum = pq.top();
        long long lastval = pq.top();
        pq.pop();
        while (!pq.empty())
        {
            int num = pq.top();
            pq.pop();
            if (num >= lastval)
            {
                num = lastval - 1;
            }
            if (num <= 0)
            {
                return -1;
            }
            sum += num;
            lastval = num;
        }
        return sum;
    }
};

int main()
{

    return 0;
}