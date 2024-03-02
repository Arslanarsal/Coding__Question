#include <bits/stdc++.h>
using namespace std;
/*
    Time Complexity: O(n*sqrt(n))

    Space Complexity: O(1)

    Where 'n' is the given integer.
*/

// int sumOfAllDivisors(int n)
// {
//     int ans = 0;

//     // Iterating over all 'i'.
//     for (int i = 1; i <= n; i++)
//     {

//         // Calculating the value of ’sumOfDivisors(i)’ for current 'i'.
//         for (int j = 1; j * j <= i; j++)
//         {
//             if (i % j == 0)
//             {

//                 // Avoid counting sqrt(i) twice.
//                 if (i / j == j)
//                 {
//                     ans += j;
//                 }
//                 else
//                 {
//                     ans += j + i / j;
//                 }
//             }
//         }
//     }

//     return ans;
// }


/*
    Time Complexity: O(n)

    Space Complexity: O(1)

    Where 'n' is the given integer.
*/

int sumOfAllDivisors(int n)
{
    int ans = 0;

    // Iterating over all 'i'. Each 'i' contributes to final answer
    // exactly 'floor(n/i)' times.
    for (int i = 1; i <= n; i++)
    {
        ans += i * (n / i);
    }

    return ans;
}


int main()
{
    // cout << sumOfAllDivisors(10);

    return 0;
}