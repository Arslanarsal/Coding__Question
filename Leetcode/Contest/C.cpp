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
                nth_element(board[i].begin(), board[i].end() - 3, board[i].end());
                sort(board[i].end() - 3, board[i].end());
                for (int k = board[i].size() - 3; k < m; k++)
                {
                    arr[i][j] = board[i][k];
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout<<arr[i][j];
            }
        }
        return 0;
    }
};

int main()
{

    return 0;
}