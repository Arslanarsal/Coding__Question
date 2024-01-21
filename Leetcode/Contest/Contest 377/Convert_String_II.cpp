#include <bits/stdc++.h>
using namespace std;

int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<string> orignal = {"a", "b", "c", "c", "e", "d"};
    vector<string> changed = {"b", "c", "b", "e", "b", "e"};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    // Solution sol;
    // cout << sol.minimumCost(source, target, orignal, changed, cost);

    return 0;
}