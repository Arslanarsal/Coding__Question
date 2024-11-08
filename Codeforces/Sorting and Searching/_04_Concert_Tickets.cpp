// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace std;
// using namespace __gnu_pbds;

// #define fastio                        \
//     ios_base::sync_with_stdio(false); \
//     cin.tie(NULL);                    \
//     cout.tie(NULL);

// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> oSet; // [find_by_order ==> given address at index] |==| [order_of_key ==> Number of element smaller then X]y
// #define int long long int
// #define ld long double
// const int mod = 1e9 + 7;
// int t, n, q, m, x;
// int arr[200006];

// int32_t main()
// {
//     fastio;
//     t = 1;
//     // cin >> t;
//     while (t--)
//     {
//         cin >> n >> m;
//         oSet ot;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> x;
//             ot.insert(x);
//         }
//         for (int i = 0; i < m; i++)
//         {
//             cin >> arr[i];
//         }

//         for (int i = 0; i < m; i++)
//         {
//             auto it = ot.order_of_key(arr[i]);

//             if ((*ot.find_by_order(it)) == arr[i])
//             {
//                 auto add = ot.find_by_order(it);
//                 ot.erase(add);
//                 cout << arr[i] << "\n";
//             }
//             else if (it > 0)
//             {
//                 auto add = ot.find_by_order(it - 1);
//                 cout << *add << "\n";
//                 ot.erase(add);
//             }
//             else
//             {
//                 cout << -1 << "\n";
//             }
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);

#define int long long
const int mod = 1e9 + 7;
int t, n, q, m, x;
int arr[200006];

int32_t main()
{
    fastio;
    t = 1;
    // cin >> t;
    while (t--)
    {
        cin >> n >> m;
        multiset<int> ms;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            ms.insert(x);
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < m; i++)
        {
            auto it = ms.upper_bound(arr[i]);

            if (it == ms.begin())
            {
                cout << -1 << "\n"; 
            }
            else
            {
                --it; 
                cout << *it << "\n";
                ms.erase(it); 
            }
        }
    }

    return 0;
}
