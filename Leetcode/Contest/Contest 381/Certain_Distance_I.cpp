#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countOfPairs(int n, int x, int y)
    {
        vector<int> res(n);
        if (x > y)
            swap(x, y);
        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; j <= n; ++j)
            {
                long long d = min(j - i, abs(x - i) + abs(y - j) + 1);
                res[d - 1] += 2;
            }
        return res;
    }
};

int main()
{

    return 0;
}