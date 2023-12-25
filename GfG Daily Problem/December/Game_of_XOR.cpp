#include <bits/stdc++.h>
using namespace std;

int gameOfXor(int N, int A[])
{
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = A[i];
        ans^=temp;
        for (int j = i+1; j < N; j++)
        {
            temp = temp^A[j];
            ans^=temp;
        }
    }
    return ans;
    
}

int main()
{
    int v[] = {1,2};
    cout<<gameOfXor(2,v);

    return 0;
}