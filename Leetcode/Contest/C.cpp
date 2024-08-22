#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumValueSum(vector<vector<int>> &board)
    {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> arr(n, vector<int>(3, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sort(board[i].begin(), board[i].end());
            }
        }
        int ans = INT_MIN;
        for (int i = 0; i < n - 3; i++)
        {
            for (int j = m - 3; j < m; j++)
            {
                int temp = board[i][j];
                for (int i = 0; i < count; i++)
                {
                    /* code */
                }
                
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}