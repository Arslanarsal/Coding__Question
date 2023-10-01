#include <bits/stdc++.h>
using namespace std;

int minDeletions(string s)
{
    vector<int> v(26);
    for (int i = 0; i < s.length(); i++)
    {
        v[s[i] - 'a']++;
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    int maxf = v[0] - 1;
    for (int i = 1; i < 26; i++)
    {
        if (v[i] != 0)
        {
            if (v[i] > maxf)
            {
                if (maxf > 0)
                {
                    ans += (v[i] - maxf);
                }
                else
                {
                    ans += v[i];
                }
            }
        }
        maxf = min(maxf - 1, v[i] - 1);
    }

    return ans;
}

int main()
{
    cout << minDeletions("ceabaacb");

    return 0;
}