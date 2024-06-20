#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7; // Modulo value for the result

// Recursive function to calculate exponentiation using binary exponentiation
int binExpRec(int a, int b)
{
    if (b == 0)
    {
        return 1;
    }
    int res = binExpRec(a, b / 2);
    if (b & 1)
    {
        return a * ((res * 1LL * res) % M) % M;
    }
    return (res * 1LL * res) % M;
}

long long binExpIte(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % M;
        }
        a = (a * 1LL * a) % M;
        b >>= 1;
    }
    return ans;
}

int main()
{
    // Example usage of both recursive and iterative functions
    cout << "Result using recursive binary exponentiation: " << binExpRec(2, 3) << endl;
    cout << "Result using iterative binary exponentiation: " << binExpIte(2, 3) << endl;

    // Note: pow() function from <cmath> library calculates floating-point exponentiation
    // It may not give accurate results for large integers and isn't recommended for modulo arithmetic
    cout << "Result using pow() function (not recommended for modulo arithmetic): " << pow(2, 3);

    return 0;
}

//(a^b)%M

// for a
//  IF a is greater assume a is 1e18 then first take mode (a%b) then continue If a is 2^1028 then first get binary exponentiation for a and then got for next; It a simple case;

// For M;
// if M is greater then what do

long long binMultiply(long long a, long long b)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans + a) % M;
        }
        a = (a + a) % M;
        b >>= 1;
    }
    return ans;
}

long long binExpIte(long long a, long long b)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = binMultiply(ans, a) % M;
        }
        a = binMultiply(a, a) % M;
        b >>= 1;
    }
    return ans;
}


//For b is greater

long long binExpIte(long long a, long long b, long long m)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
        {
            ans = (ans * 1LL * a) % m;
        }
        a = (a * 1LL * a) % m;
        b >>= 1;
    }
    return ans;
}
// a^b^c    50^64^32
// binExpIte(50 , binExpIte(64 , 32 , M-1)  , M);