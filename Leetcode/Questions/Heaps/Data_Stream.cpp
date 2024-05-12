#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
    priority_queue<int> spq;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        spq.push(num); // Push to min heap first

        // Balance the heaps
        pq.push(spq.top());
        spq.pop();

        // Ensure pq has no more than one extra element than spq
        if (pq.size() > spq.size() + 1)
        {
            spq.push(pq.top());
            pq.pop();
        }
    }

    double findMedian()
    {
        if (pq.size() > spq.size())
        {
            return pq.top();
        }
        return ((double)pq.top() + (double)spq.top()) / 2;
    }
};

int main()
{

    return 0;
}