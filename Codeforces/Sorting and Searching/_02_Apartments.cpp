#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
#define int long long int
#define ld long double
const int mod = 1e9 + 7;
int t, n, q, m;
int applicant[200006]{}, department[200006]{};
int32_t main()
{
    fastio;
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> applicant[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> department[i];
    }
    sort(applicant, applicant + n);
    sort(department, department + m);
    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if ((department[j] <= applicant[i] + t) && (department[j] >= applicant[i] - t))
        {
            i++, j++;
            ans++;
        }
        else if ((department[j] < applicant[i] - t))
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    cout << ans << "\n";

    return 0;
}