#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    int ans = 0;
    for (int i = 0; i < K; i++)
    {
        ans += Arr[i];
    }
    int temp = ans;
    for (int i = K; i < N; i++)
    {
        temp -= Arr[i - K];
        temp += Arr[i];
        if (temp > ans)
        {
            ans = temp;
        }
    }
    return ans;
}

int main()
{

    return 0;
}