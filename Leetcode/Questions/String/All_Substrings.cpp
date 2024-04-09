#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int findmin(int freq[])
    {
        int ans = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                ans = min(ans, freq[i]);
            }
        }
        return ans;
    }
    int findmax(int freq[])
    {
        int ans = INT_MIN;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] != 0)
            {
                ans = max(ans, freq[i]);
            }
        }
        return ans;
    }

public:
    int beautySum(string s)
    {
        int n = s.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            int freq[26] = {0};
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;
                int minele = findmin(freq);
                int maxele = findmax(freq);
                ans += (maxele - minele);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}