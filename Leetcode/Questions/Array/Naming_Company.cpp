#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long distinctNames(vector<string> &s)
    {
        int n = s.size();
        unordered_set<string> st[26];

        for (auto &&it : s)
        {
            st[it[0] - 'a'].insert(it.substr(1));
        }
        long long ans = 0;

        for (int i = 0; i < 26; i++)
        {
            for (int j = i + 1; j < 26; j++)
            {
                int common = 0;
                for (auto &&word : st[i])
                {
                    if (st[j].count(word))
                    {
                        common++;
                    }
                }

                int pair = (st[i].size() - common) * (st[j].size() - common);
                ans += 2 * pair;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}