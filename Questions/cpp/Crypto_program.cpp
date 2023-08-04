#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n = 10;
    for (int i = 0; i < 2; i++)
    {
        n+= (.1*n);
    }
    cout<<n;
    
    return 0;
}