#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long wonderfulSubstrings(string word)
    {
        unordered_map<int, int> mp;
        mp[0] = 1;
        long long ans = 0;
        int max_xor = 0;

        for (auto &&ch : word)
        {
            int shift = ch - 'a';
            max_xor ^= (1 << shift);
            ans += mp[max_xor];
            for (char i = 'a'; i <= 'j'; i++)
            {
                shift = i - 'a';
                int check = max_xor ^ (1 << shift);
                ans+= mp[check];

            }
            mp[max_xor]++;
        }
        return ans;
    }
};

int main()
{

    return 0;
}