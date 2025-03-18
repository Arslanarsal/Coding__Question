#include <bits/stdc++.h>
using namespace std;

class Spreadsheet
{
    vector<vector<int>> arr;

public:
    Spreadsheet(int rows)
    {
        arr.resize(rows + 1, vector<int>(26));
    }

    void setCell(string cell, int value)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            int digit = cell[i] - '0';
            col = col * 10;
            col += digit;
        }
        arr[row][col] = value;
    }

    void resetCell(string cell)
    {
        int row = cell[0] - 'A';
        int col = 0;
        for (int i = 1; i < cell.size(); i++)
        {
            int digit = cell[i] - '0';
            col = col * 10;
            col += digit;
        }
        arr[row][col] = 0;
    }

    int getValue(string formula)
    {
        if (formula[3] >= 'A' && formula[3] <= 'Z')
        {
            int row = formula[3] - 'A';
            int col = 0;
            for (int i = 4; formula[i] != '+'; i++)
            {
                int digit = formula[i] - '0';
                col = col * 10;
                col += digit;
            }
        }
    }
};

int32_t main()
{

    return 0;
}