#include <bits/stdc++.h>
using namespace std;

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int ind = -1;
    int cnt_max = -1;

    for (int i = 0; i < n; i++)
    {
        int cnt = m - *lower_bound(matrix[i].begin(), matrix[i].end(), 1);
        if (cnt > cnt_max)
        {
            cnt_max = cnt;
            ind = i;
        }
    }
    return cnt_max;
}

int main()
{

    return 0;
}