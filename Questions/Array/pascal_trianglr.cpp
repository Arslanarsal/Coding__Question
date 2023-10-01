#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows)
{
    vector<int> temp;
    vector<vector<int>> ans;
    if (numRows == 1)
    {
        temp.push_back(1);
        ans.push_back(temp);
        return ans;
    }
    temp.push_back(1);
    ans.push_back(temp);
    temp.push_back(1);
    ans.push_back(temp);

    for (int i = 2; i < numRows; i++)
    {
        temp.clear();
        temp.push_back(1);
        for (int j = 1; j < i; j++)
        {
            temp.push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
        }
        temp.push_back(1);
        ans.push_back(temp);
    }
    return ans;
}

void display(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> v = generate(4);
    display(v);

    return 0;
}