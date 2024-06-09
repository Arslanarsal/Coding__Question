#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        vector<int> freq(100, 0);
        for (auto &&i : s)
        {
            freq[i - 'A']++;
        }
        sort(freq.begin(), freq.end(), [](int a, int b)
             { return a > b; });
        int ans = 0;
        int flage = false;
        for (int i = 0; i < 100; i++)
        {
            if (freq[i] & 1)
            {
                flage = true;
                ans += freq[i] - 1;
            }
            else
            {
                ans += freq[i];
            }
        }
        if (flage)
        {
            ans+=1;
        }
        
        return ans;
    }
};

int main()
{

    return 0;
}