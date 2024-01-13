#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<string> &original, vector<string> &changed, vector<int> &cost)
    {
        unordered_map<string, int> lebal;
        for (auto &&i : original)
        {
            if (!lebal.count(i))
            {
                lebal[i] = lebal.size();
            }
        }
        for (auto &&i : changed)
        {
            if (!lebal.count(i))
            {
                lebal[i] = lebal.size();
            }
        }
        
    }
};

int main()
{
    string source = "abcd";
    string target = "acbe";
    vector<string> orignal = {"a", "b", "c", "c", "e", "d"};
    vector<string> changed = {"b", "c", "b", "e", "b", "e"};
    vector<int> cost = {2, 5, 5, 1, 2, 20};
    Solution sol;
    sol.minimumCost(source, target, orignal, changed, cost);

    return 0;
}