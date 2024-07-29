#include <bits/stdc++.h>
using namespace std;

void solve(int idx, string s, vector<string> &ans, int &n)
{
    if (idx == n)
    {
        ans.push_back(s);
        return;
    }
    unordered_set<char> swapped;
    for (int i = idx; i < n; i++)
    {
        if (swapped.find(s[i]) == swapped.end())
        {
            swapped.insert(s[i]);
            swap(s[idx], s[i]);
            solve(idx + 1, s, ans, n);
            swap(s[idx], s[i]);
        }
    }
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    sort(s.begin(), s.end());

    vector<string> ans;
    solve(0, s, ans, n);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    int m = ans.size();
    cout << m << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << ans[i] << "\n";
    }

    return 0;
}
