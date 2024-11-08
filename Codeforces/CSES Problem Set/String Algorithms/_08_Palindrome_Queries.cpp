#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll HASH = 257, MOD = 1e9 + 7;

int N, Q;
vector<ll> powH(200005, 1);                                   // Precomputed powers of HASH
vector<ll> forward_hash(200005, 0), backward_hash(200005, 0); // Hash arrays for forward and backward directions

// Function to update the hash arrays when a character is changed
void updateHash(int idx, char c)
{
    // Update the forward hash
    forward_hash[idx + 1] = (forward_hash[idx] + powH[idx] * (ll)c % MOD) % MOD;
    // Update the backward hash
    backward_hash[N - idx] = (backward_hash[N - idx + 1] + powH[N - 1 - idx] * (ll)c % MOD) % MOD;
}

// Function to compute hash of a substring in forward direction
ll getForwardHash(int l, int r)
{
    ll hash_value = (forward_hash[r + 1] - forward_hash[l] + MOD) % MOD;
    return (hash_value * powH[N - 1 - r]) % MOD; // Adjust for position
}

// Function to compute hash of a substring in backward direction
ll getBackwardHash(int l, int r)
{
    ll hash_value = (backward_hash[N - l] - backward_hash[N - r - 1] + MOD) % MOD;
    return (hash_value * powH[l]) % MOD; // Adjust for position
}

int main()
{
    cin >> N >> Q;

    // Precompute powers of HASH modulo MOD
    for (int i = 1; i < N; i++)
    {
        powH[i] = (powH[i - 1] * HASH) % MOD;
    }

    string s;
    cin >> s;

    // Initialize forward and backward hashes
    for (int i = 0; i < N; i++)
    {
        updateHash(i, s[i]);
    }

    while (Q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        { // Update character at position
            int k;
            char c;
            cin >> k >> c;
            k--;
            s[k] = c;
            updateHash(k, c); // Update both forward and backward hashes
        }
        else if (t == 2)
        { // Check if the substring is a palindrome
            int l, r;
            cin >> l >> r;
            l--, r--;

            // Compare the forward and backward hashes of the substring
            if (getForwardHash(l, r) == getBackwardHash(l, r))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
