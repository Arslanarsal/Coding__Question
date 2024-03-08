#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (ans.empty() || ans[ans.size() - 1][1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
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
    vector<vector<int>> v = {{1, 4}, {2, 4}};
    display(merge(v));

    return 0;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        int j = ans.size() - 1;
        if (ans.empty() || ans[j][1] < arr[i][0])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans[j][1] = max(ans[ans.size() - 1][1], arr[i][1]);
        }
    }
    return ans;
}