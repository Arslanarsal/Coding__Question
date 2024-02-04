#include <bits/stdc++.h>
using namespace std;

void swap(int a, int b)
{
    a = a ^ b; // a ==> (a^b)
    b = a ^ b; // a ==> ((a^b)^b)  ->  (a^b^b) //
    a = a ^ b; // a ==> ((a^b)^b) Here b value is already converted into a ->  (a^b^a)
    cout << a << " " << b << "\n";
}

int main()
{
    swap(3, 5);

    return 0;
}