#include <bits/stdc++.h>
using namespace std;

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    if (start.size() == 0 || end.size() == 0)
    {
        return 0;
    }
    int ans = 1;
    unordered_map<int, int> umap;
    for (int i = 0; i < end.size(); i++)
    {
        if (umap.find(end[i]) == umap.end())
        {
            umap[end[i]] = i;
        }
        else
        {
            if (start[umap[end[i]]] < start[i])
            {
                umap[end[i]] = i;
            }
        }
    }
    sort(end.begin(), end.end());
    int temp = end[0];
    for (int i = 1; i < end.size(); i++)
    {
        if (temp <= start[umap[end[i]]])
        {
            temp = end[i];
            ans++;
        }
    }
    return ans;
}
int main()
{

    return 0;
}

