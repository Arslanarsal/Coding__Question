#include <bits/stdc++.h>
using namespace std;

vector<int> printNos(int i, int &x, vector<int> &ans)
{
    if (i > x)
    {
        return ans;
    }
    ans.push_back(i);
    return printNos(i + 1, x, ans);
}

vector<int> printNos(int x)
{
    vector<int> ans;
    return printNos(1, x, ans);
}

int main()
{

    return 0;
}