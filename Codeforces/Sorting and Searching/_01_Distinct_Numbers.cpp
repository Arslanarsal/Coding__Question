#include <bits/stdc++.h>
using namespace std;
int main()
{
    // Sample Input
    int N;
    cin >> N;
    set<int> s;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        s.insert(x);
    }
    cout << s.size();
}
