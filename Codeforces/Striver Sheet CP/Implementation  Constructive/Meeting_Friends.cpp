#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    cout << max(n, max(m, k)) - min(n, min(m, k));
    return 0;
}