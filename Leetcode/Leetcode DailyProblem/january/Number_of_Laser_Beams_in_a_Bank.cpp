#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ans = 0, pre = 0;
        for (auto &&s : bank)
        {
            int count = 0;
            for (auto &&i : s)
            {
                if (i == '1')
                {
                    count++;
                }
            }

            if (count != 0)
            {
                ans += (pre * count);
                pre = count;
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}