#include <bits/stdc++.h>
using namespace std;

class solve
{
public:
    long long sum, x;
    multiset<pair<long long, long long>> setk, setx;
    unordered_map<long long, long long> mp;
    solve(long long a)
    {
        a = x;
        sum = 0;
    }
    void insert(long long ele)
    {
        mp[ele]++;
        long long first = mp[ele];
        long long second = ele;
        if (setk.count({first - 1, second}))
        {
            setk.erase({first - 1, second});
        }
        setk.insert({first, second});
        if (setx.size() < x)
        {
            setx.insert(*setk.rbegin());
            setk.erase(*setk.rbegin());
            x++;
        }
    }
    void delet(long long ele)
    {
        long long first = mp[ele];
        long long second = ele;
        if (setk.count({first, second}))
        {
            setk.erase({first, second});
            mp[ele]--;
            if (mp[ele] > 0)
            {
                setk.insert({first - 1, second});
            }
        }
        else
        {
            setx.erase({first, second});
            mp[ele]--;
            if (mp[ele] > 0)
            {
                setk.insert({first - 1, second});
            }
            if (setx.size() < x)
            {
                setx.insert(*setk.rbegin());
                setk.erase(*setk.rbegin());
            }
        }
    }
};

class Solution
{
public:
<<<<<<< HEAD
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
=======
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
>>>>>>> cfc39bffb3206a568c012c1c993005a6947778bf
    }
};

int main()
{

    return 0;
}