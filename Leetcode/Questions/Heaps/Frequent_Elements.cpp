#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> mp;
        for (auto &&i : nums)
        {
            mp[i]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto &&i : mp)
        {
            pq.push({i.second, i.first});
        }
        vector<int> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    }
};

int main()
{

    return 0;
}