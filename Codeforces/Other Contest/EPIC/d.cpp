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

    // int &result = dp[index][remaining];
    // if (visited[index][remaining] == current_id)
    //     return result;
    // visited[index][remaining] = current_id;
    int result = solve(index + 1, remaining + 1, values);
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
    for (auto it : value_counts)
    {
        frequency[it.first] = it.second;
        values.push_back(it.first);
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

// #include <bits/stdc++.h>
// using namespace std;

// int solve(int ind, vector<int> &freq, bool turn, int &n)
// {
//     if (ind == n)
//     {
//         return 0;
//     }


//     if (turn)
//     {
//         for (int i = ind; i < n; i++)
//         {
//             if (freq[i])
//             {
//                 return 1 + solve(i + 1, freq, !turn, n);
//             }
//         }
//     }
//     else
//     {
//         int temp = INT_MAX;
//         int j = 0;
//         for (int i = ind; i < n; i++)
//         {
//             if (freq[i])
//             {
//                 freq[i]--;
//                 int ret = solve(ind, freq, !turn, n);
//                 if (ret < temp)
//                 {
//                     temp = ret;
//                     j = i;
//                 }

//                 freq[i]++;
//             }
//         }
//         if (temp == INT_MAX)
//         {
//             return  0;
//         }
//         return temp;
//     }
//     return 0;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int arr[n];
//         map<int, int> mp;
//         for (int i = 0; i < n; i++)
//         {
//             int x;
//             cin >> x;
//             arr[i] = x;
//             mp[x]++;
//         }
//         vector<int> freq;
//         for (auto &&it : mp)
//         {
//             freq.push_back(it.second);
//         }
//         int m = freq.size();
//         int ans = solve(0, freq, true, m);
//         cout << ans << "\n";
//     }

//     return 0;
// }
