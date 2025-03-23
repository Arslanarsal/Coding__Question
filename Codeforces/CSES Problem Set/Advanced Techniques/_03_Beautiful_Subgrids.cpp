#include <bits/stdc++.h>
using namespace std;
#pragma GCC target("popcnt")
// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);

#define int long long
#define ld long double
int t, n, q, m, x;
const int N = 3001;

bitset<N> bit[N];

int32_t main()
{

    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> bit[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int counts = (bit[i] & bit[j]).count();
            ans += (counts * (counts - 1)) / 2;
        }
    }
    cout << ans << "\n";

    return 0;
}

// #include <bits/stdc++.h>
// #pragma GCC target("popcnt")

// using namespace std;
// typedef long long ll;
// const int maxN = 3005;

// int N;
// ll ans;
// bitset<maxN> B[maxN];

// int f(int X){
//     return X*(X-1);
// }

// int main(){
//     cin.sync_with_stdio(0);
//     cin.tie(0);

//     cin >> N;
//     for(int i = 0; i < N; i++)
//         cin >> B[i];

//     for(int i = 0; i < N; i++)
//         for(int j = i+1; j < N; j++)
//             ans += f((B[i]&B[j]).count());

//     cout << (ans>>1);
// }
