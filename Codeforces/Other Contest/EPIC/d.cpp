// #include <bits/stdc++.h>

// using namespace std;
// const int MAXN = 1e5 + 7, MOD = 1e9 + 7;

// int frequency[5005];
// int dp[5005][5005];
// int visited[5005][5005];
// int current_id;
// int n;

// int solve(int index, int remaining, vector<int> &values)
// {
//     if (index >= n)
//         return 0;

//     // int &result = dp[index][remaining];
//     // if (visited[index][remaining] == current_id)
//     //     return result;
//     // visited[index][remaining] = current_id;
//     int result = solve(index + 1, remaining + 1, values);
//     if (remaining >= frequency[values[index]])
//     {
//         result = max(result, 1 + solve(index + 1, remaining - frequency[values[index]], values));
//     }
//     return result;
// }

// void solve_test_case()
// {
//     cin >> n;

//     vector<int> values;
//     map<int, int> value_counts;
//     for (int i = 0; i < n; ++i)
//     {
//         int x;
//         cin >> x;
//         value_counts[x]++;
//     }
//     for (auto it : value_counts)
//     {
//         frequency[it.first] = it.second;
//         values.push_back(it.first);
//     }
//     n = values.size();
//     cout << n - solve(1, 1, values) << '\n';
//     ++current_id;
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     int test_cases = 1;
//     cin >> test_cases;
//     current_id = 1;
//     while (test_cases--)
//     {
//         solve_test_case();
//     }
// }

// ------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>----------------------

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

// -----------------------------------------------------------------------------------------------

// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// void solve()
// {
//     int n;
//     cin >> n;
//     map<int, int> u;
//     for (int i = 0, a; i < n; i++)
//     {
//         cin >> a;
//         u[a]++;
//     }
//     int i = 1;
//     n = u.size();
//     vector<int> dp(n + 1, 0);
//     for (auto &x : u)
//     {
//         x.second++;
//         for (int j = i; j >= x.second; j--)
//         {
//             dp[j] = max(dp[j], dp[j - x.second] + 1);
//         }
//         i++;
//     }
//     sort(dp.begin(), dp.end());
//     cout << n - dp.back() << '\n';
// }
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }

// ==================================================================
#include <bits/stdc++.h>
using namespace std;

#define MAX_N 5010
using ll = long long;

ll memo[MAX_N][MAX_N];
ll freq[MAX_N];

#define MEMO memo[index][ascCount]

ll findMaxAscending(ll index, ll ascCount)
{
    if (ascCount < 0)
        return -2;
    if (!index)
        return ascCount ? -2 : 0;
    if (~MEMO)
        return MEMO;
    if (freq[index])
        MEMO = findMaxAscending(index - 1, ascCount - 1);
    else
        MEMO = findMaxAscending(index - 1, ascCount);
    if (findMaxAscending(index - 1, ascCount) != -2 && findMaxAscending(index - 1, ascCount) + freq[index] <= ascCount)
    {
        if (MEMO == -2 || findMaxAscending(index - 1, ascCount) + freq[index] < MEMO)
        {
            MEMO = findMaxAscending(index - 1, ascCount) + freq[index];
        }
    }
    return MEMO;
}

int main()
{
    int testCases;
    cin >> testCases;
    while (testCases--)
    {
        ll numCakes;
        cin >> numCakes;
        for (int i = 0; i <= numCakes; i++)
            fill_n(memo[i], numCakes + 1, -1);
            
        for (int i = 0; i < numCakes; i++)
        {
            ll tastiness;
            cin >> tastiness;
            freq[tastiness]++;
        }
        ll answer = numCakes;
        for (int i = numCakes; i >= 0; i--)
            if (findMaxAscending(numCakes, i) != -2)
                answer = i;
        cout << answer << '\n';
        fill_n(freq, numCakes + 1, 0ll);
    }
    return 0;
}