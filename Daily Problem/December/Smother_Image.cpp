#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int n = img.size();
        int m = img[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int sum = 0;
                int count = 0;
                for (int x = i - 1; x <= i + 1; x++)
                {
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x >= 0 && x < n && y >= 0 && y < m)
                        {
                            sum += (img[x][y] & ((1 << 8) - 1));
                            count += 1;
                        }
                    }
                }
                img[i][j] |= ((sum / count) << 8);
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                img[i][j] = img[i][j] >> 8;
            }
        }
        return img;
    }
};

int main()
{

    return 0;
}