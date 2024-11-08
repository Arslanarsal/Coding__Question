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
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
    }
};

int main()
{

    return 0;
}