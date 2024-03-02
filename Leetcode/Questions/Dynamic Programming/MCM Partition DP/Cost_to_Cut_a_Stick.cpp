#include <bits/stdc++.h>
using namespace std;

class Solution
{
    int f(int i, int j, vector<int> &cuts)
    {
        if (i > j)
        {
            return 0;
        }
        int mini = 1e9;
        for (int k = i; k <= j; k++)
        {
            int step = cuts[j + 1] - cuts[i - 1] + f(i, k - 1, cuts) + f(k + 1, j, cuts);
            mini = min(mini, step);
        }
        return mini;
    } 

public:
    int minCost(int n, vector<int> &cuts)
    {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        return f(1, c, cuts);
    }
};

int main()
{

    return 0;
}