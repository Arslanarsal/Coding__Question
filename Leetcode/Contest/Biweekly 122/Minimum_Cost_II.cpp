#include <bits/stdc++.h>
using namespace std;

class Solution
{
    multiset<int> l, r;

public:
    long long minimumCost(vector<int> &nums, int k, int dist)
    {
        int n = nums.size();
        long long cnt = nums[0];
        k--;
        for (int i = 1; i <= dist + 1; i++)
        {
            cnt += nums[i];
            l.insert(nums[i]);
        }
        while (l.size() > k)
        {
            int temp = *l.rbegin();
            cnt -= temp;
            r.insert(temp);
            l.erase(l.find(temp));
        }
        long long ans = cnt;
        for (int i = dist + 2; i < n; i++)
        {
            int pre = nums[i - dist - 1];
            if (l.find(pre) != l.end())
            {
                cnt -= pre;
                l.erase(l.find(pre));
            }
            else
            {
                r.erase(r.find(pre));
            }
            int cur = nums[i];
            if (cur < *l.rbegin())
            {
                cnt += cur;
                l.insert(cur);
            }
            else
            {
                r.insert(cur);
            }
            while (l.size() < k)
            {
                int temp = *r.begin();
                cnt += temp;
                l.insert(temp);
                r.erase(r.find(temp));
            }
            while (l.size() > k)
            {
                int temp = *l.rbegin();
                cnt -= temp;
                r.insert(temp);
                l.erase(l.find(temp));
            }
            ans = min(ans, cnt);
        }
        return ans;
    }
};

int main()
{

    return 0;
}