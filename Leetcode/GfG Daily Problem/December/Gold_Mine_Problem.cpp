#include <bits/stdc++.h>
using namespace std;

int maxGold(int n, int m, vector<vector<int>> M)
{
    for (int j = m - 2; j >= 0; j--)
    {
        for (int i = 0; i < n; i++)
        {
            int upright = 0;
            int right = 0;
            int downright = 0;
            right = M[i][j + 1];

            // Check if the index is valid before accessing the elements
            if (i != 0)
                upright = M[i - 1][j + 1];
            if (i != n - 1)
                downright = M[i + 1][j + 1];

            // Calculate the maximum value
            M[i][j] = M[i][j] + max(upright, max(right, downright));
        }
    }

    // Find the maximum gold collected
    int ans = M[0][0];
    for (int i = 0; i < n; i++)
    {
        if (M[i][0] > ans)
        {
            ans = M[i][0];
        }
    }

    return ans;
}

int main()
{

    return 0;
}