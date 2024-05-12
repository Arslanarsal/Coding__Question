#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
    priority_queue<int> spq;
    priority_queue<int, greater<int>> lpq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        for (auto &&i : nums)
        {
            spq.push(i);
        }
        for (int i = 0; i < k - 1; i++)
        {
            lpq.push(spq.top());
            spq.pop();
        }
    }

    int add(int val)
    {
        if (val == spq.top())
        {
            return val;
        }
        if (val > spq.top())
        {
            spq.push(val);
            int ret = spq.top();
            spq.pop();
            return ret;
        }
        lpq.push(val);
        int ret = lpq.top();
        lpq.pop();
        return ret;
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main()
{

    return 0;
}