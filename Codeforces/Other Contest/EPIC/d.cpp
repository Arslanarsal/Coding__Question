#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e5 + 7, MOD = 1e9 + 7;

int frequency[5005];
int dp[5005][5005];
int visited[5005][5005];
int current_id;
int n;

int solve(int index, int remaining, vector<int> &values)
{
    if (index >= n)
        return 0;
        
    int &result = dp[index][remaining];
    if (visited[index][remaining] == current_id)
        return result;
    visited[index][remaining] = current_id;
    result = solve(index + 1, remaining + 1, values);
    if (remaining >= frequency[values[index]])
    {
        result = max(result, 1 + solve(index + 1, remaining - frequency[values[index]], values));
    }
    return result;
}

void solve_test_case()
{
    cin >> n;

    vector<int> values;
    map<int, int> value_counts;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        value_counts[x]++;
    }
    for (auto [value, count] : value_counts)
    {
        frequency[value] = count;
        values.push_back(value);
    }
    n = values.size();
    cout << n - solve(1, 1, values) << '\n';
    ++current_id;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int test_cases = 1;
    cin >> test_cases;
    current_id = 1;
    while (test_cases--)
    {
        solve_test_case();
    }
}
