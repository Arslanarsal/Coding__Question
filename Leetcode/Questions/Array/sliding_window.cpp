#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 123; 
    int k = 3;
    // cout << (pow(10, k - 1));
    cout << (num % int(pow(10, k - 1))) * 10 + 4;
    // cout << (num % (int)(pow(10, k - 1)))*10;
    // cout << (num % (int)(pow(10, k - 1)))*10;
    // cout << (num % (int)(pow(10, k - 1)))*10;
    return 0;
}