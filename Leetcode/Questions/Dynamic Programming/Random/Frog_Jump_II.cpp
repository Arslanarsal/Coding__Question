#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxJump(vector<int> &stones)
    {
        int res = stones[1], n = stones.size();
        for (int i = 2; i < n; i++)
        {
            res = max(res, stones[i] - stones[i - 2]);
        }
        return res;
    }
};

int main()
{

    return 0;
}