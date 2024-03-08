#include <bits/stdc++.h>
using namespace std;

vector<int> superiorElements(vector<int> &a)
{
    int n = a.size();
    int num = a[n - 1];
    int maxinum = a[n - 1];
    vector<int> ans;
    ans.push_back(a[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] > maxinum)
        {
            ans.push_back(a[i]);
            maxinum = a[i];
        }
    }
    return ans;
}

int main()
{

    return 0;
}