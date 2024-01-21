#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumPushes(string word)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int cnt[26] = {}, ans = 0, key = 0;
        for (auto &&i : word)
            ++cnt[i - 'a'];

        sort(begin(cnt), end(cnt), greater<int>());
        for (auto &&c : cnt)
            ans += (1 + key++ / 8) * c;

        return ans;
    }
};

int main()
{

    return 0;
}