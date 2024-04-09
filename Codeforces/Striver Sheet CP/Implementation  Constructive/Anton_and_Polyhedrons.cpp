#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<string, int> mp{{"Tetrahedron", 4}, {"Cube", 6}, {"Octahedron", 8}, {"Dodecahedron", 12}, {"Icosahedron", 20}};
    int n;
    int ans = 0;
    cin >> n;
    while (n--)
    {
        string input;
        cin >> input;
        ans += mp[input];
    }
    cout << ans;

    return 0;
}