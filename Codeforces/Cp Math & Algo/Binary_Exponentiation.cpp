#include <bits/stdc++.h>
using namespace std;

int M = 1e9 + 7; // Modulo value for the result

// Recursive function to calculate exponentiation using binary exponentiation
int binExpRec(int a, int b)
{
    if (b == 0)
    {
        return 1; // Base case: Anything raised to power 0 is 1
    }
    int res = binExpRec(a, b / 2); // Recursively compute a^(b/2)
    if (b & 1)                     // If b is odd
    {
        return a * ((res * 1LL * res) % M) % M; // Multiply a with a^(b/2) * a^(b/2) % M
    }
    return (res * 1LL * res) % M; // Otherwise just return a^(b/2) * a^(b/2) % M
}

// Iterative function to calculate exponentiation using binary exponentiation
int binExpIte(int a, int b)
{
    int ans = 1;
    while (b)
    {
        if (b & 1) // If b is odd
        {
            ans = (ans * 1LL * a) % M; // Multiply ans with a % M
        }
        a = (a * 1LL * a) % M; // Square a and take modulo M
        b >>= 1;               // Divide b by 2
    }
    return ans;
}

int main()
{
    // Example usage of both recursive and iterative functions
    cout << "Result using recursive binary exponentiation: " << binExpRec(21, 3) << endl;
    cout << "Result using iterative binary exponentiation: " << binExpIte(21, 3) << endl;

    // Note: pow() function from <cmath> library calculates floating-point exponentiation
    // It may not give accurate results for large integers and isn't recommended for modulo arithmetic
    cout << "Result using pow() function (not recommended for modulo arithmetic): " << pow(21, 3);

    return 0;
}
