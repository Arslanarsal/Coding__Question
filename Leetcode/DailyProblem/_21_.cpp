#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int strangePrinter(string s)
    {
        int n = s.size();
        vector<int> v(26, 0);
        int i = 0;
        while (i < n)
        {
            char ch = s[i];
            v[ch - 'a']++;
            while (i < n && s[i] == ch)
            {
                i++;
            }
        }
        int sum = 0;
        int maxele = INT_MIN;
        for (int i = 0; i < 26; i++)
        {
            sum += v[i];
            maxele = max(maxele, v[i]);
        }
        sum -= maxele;
        sum += 1;
        cout << sum;
        return sum;
    }
};

int main()
{

    return 0;
}