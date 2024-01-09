#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximizeSquareArea(int m, int n, vector<int> &h, vector<int> &v)
    {
        int mod = 1e9 + 7;
        unordered_map<int, bool> s1;
        v.push_back(1);
        h.push_back(1);
        v.push_back(n);
        h.push_back(m);
        sort(v.begin(), v.end());
        sort(h.begin(), h.end());
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                s1[(v[j] - v[i])] = 1;
            }
        }
        long long ans = -1;
        for (int i = 0; i < h.size(); i++)
        {
            for (int j = i + 1; j < h.size(); j++)
            {
                if (s1.find(h[j] - h[i]) != s1.end())
                {
                    ans = max(ans, (h[j] - h[i]) * 1LL * (h[j] - h[i]));
                }
            }
        }

        return ans % mod;
    }
};

int main()
{

    return 0;
}