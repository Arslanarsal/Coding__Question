#include <bits/stdc++.h>
using namespace std;
string oddEven(int N)
{
    return N & 1 ? "odd" : "even";
}
int main()
{
    cout << oddEven(13);

    return 0;
}