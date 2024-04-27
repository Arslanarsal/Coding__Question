#include <bits/stdc++.h>
using namespace std;

vector<int> countPrimes(int n)
{
    vector<int> ans;
    int root = sqrt(n);
    for (int i = 2; i <= root; i++)
    {
        if (((n / i) * i) == n)
        {
            if (n / i != i)
            {
                ans.push_back(n / i);
            }
            ans.push_back(i);
        }
    }
    sort(ans.begin(), ans.end());
   
    return ans;
}

int main()
{

    return 0;
}