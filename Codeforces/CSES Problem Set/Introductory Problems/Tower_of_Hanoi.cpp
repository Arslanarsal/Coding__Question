#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, int from_rod, int to_rod, int aux_rod, vector<pair<int, int>> &ans)
{
    if (n == 0)
    {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod, ans);
    ans.push_back({from_rod, to_rod});
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod, ans);
}

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> ans;
    towerOfHanoi(N, 1, 3, 2, ans);
    int n = ans.size();
    cout << n << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }

    return 0;
}
