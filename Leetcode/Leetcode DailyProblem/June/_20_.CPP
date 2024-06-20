#include <bits/stdc++.h>
using namespace std;

class Solution
{
    bool solve(vector<int> &position, int m, int &diff)
    {
        int n = position.size();
        m--;
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            if (position[i] - position[j] >= diff)
            {
                j = i;
                m--;
            }
            if (!m)
            {
                return true;
            }
        }
        return false;
    }

public:
    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        int low = 0;
        int high = position[n - 1];
        int ans = 0;
        while (low <= high)
        {
            int mid = (high + low) / 2;
            cout << low << " " << high << " " << mid << " \n";
            if (solve(position, m, mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        cout << ans;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> position = {79,
                            74,
                            57,
                            22};
    sol.maxDistance(position, 4);

    return 0;
}