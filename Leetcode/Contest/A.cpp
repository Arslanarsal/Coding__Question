#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
#define ld long double
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
const int mod = 1e9 + 7;
int t, n, q, m, x;

#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int minMaxSums(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        const int MOD = 1e9 + 7;

        // Precompute factorials and inverse factorials
        vector<long long> factorial(n + 1, 1);
        vector<long long> invFactorial(n + 1, 1);
        for (int i = 1; i <= n; ++i)
        {
            factorial[i] = factorial[i - 1] * i % MOD;
        }

        // Compute inverse factorials using Fermat's Little Theorem
        invFactorial[n] = pow(factorial[n], MOD - 2, MOD);
        for (int i = n - 1; i >= 1; --i)
        {
            invFactorial[i] = invFactorial[i + 1] * (i + 1) % MOD;
        }

        // Lambda function for computing nCr
        auto nCr = [&](int n, int r)
        {
            if (r > n || r < 0)
                return 0LL;
            return factorial[n] * invFactorial[r] % MOD * invFactorial[n - r] % MOD;
        };

        long long res = 0;
        // Calculate the result
        for (int size = 1; size <= k; ++size)
        {
            for (int i = 0; i < n; ++i)
            {
                long long minContrib = nCr(n - i - 1, size - 1) * nums[i] % MOD;
                long long maxContrib = nCr(i, size - 1) * nums[i] % MOD;
                res = (res + maxContrib + minContrib) % MOD;
            }
        }
        return res;
    }

private:
    // Function for modular exponentiation
    long long pow(long long base, long long exp, long long mod)
    {
        long long result = 1;
        base %= mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = result * base % mod;
            }
            base = base * base % mod;
            exp /= 2;
        }
        return result;
    }
};

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n;
    }

    return 0;
}