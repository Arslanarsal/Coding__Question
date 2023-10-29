#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(nums[i]*-1);
    }
    for (int i = k; i < nums.size(); i++)
    {
        if (pq.top() < (nums[i]*-1))
        {
            pq.pop();
            pq.push(nums[i]*-1);
        }
    }
    return pq.top();
}

int main()
{

    return 0;
}