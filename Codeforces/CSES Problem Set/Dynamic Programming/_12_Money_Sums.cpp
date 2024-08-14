#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);
    bitset<14> temp;
    temp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        cout << temp << "\n";
        temp |= temp << x;
    }
    cout << temp << "\n";
    // vector<int> ans;
    // for (int i = 1; i < 10; i++)
    // {
    //     if (temp[i])
    //     {
    //         ans.push_back(i);
    //     }
    // }
    // int m = ans.size();
    // cout << m << "\n";

    // for (int i = 0; i < m; i++)
    // {
    //     cout << ans[i] << " ";
    // }

    return 0;
}