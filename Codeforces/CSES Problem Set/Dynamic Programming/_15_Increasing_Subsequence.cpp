#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n;
vector<int> arr, ans;

int32_t main()
{
    cin >> n;
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int m = ans.size();
        if (ans.empty() || ans[m - 1] < num)
        {
            ans.push_back(num);
        }
        else
        {
            int idx = lower_bound(ans.begin(), ans.end(), num) - arr.begin();
            arr[idx] = num;
        }
    }
    int m = ans.size();
    cout << m << "\n";
    return 0;
}