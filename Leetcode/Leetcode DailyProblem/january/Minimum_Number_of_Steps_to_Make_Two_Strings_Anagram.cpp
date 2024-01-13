#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSteps(string s, string t)
    {
        int n = s.size();
        int ans = 0;
        unordered_map<int, int> n1(26);
        unordered_map<int, int> n2(26);
        for (int i = 0; i < n; i++)
        {
            n1[s[i] - 'a']++;
            n2[t[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (n1[i] > n2[i])
            {
                ans += (n1[i] - n2[i]);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}