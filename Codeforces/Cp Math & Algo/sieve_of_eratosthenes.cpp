#include <bits/stdc++.h>
using namespace std;

const int N = 100;
vector<bool> isPrime(N, 1);
vector<int> lp(N, 0), hp(N), divisiors[N];

int main()
{

    // ------------------->>>>> Prime Number Identification
    // isPrime[0] = isPrime[1] = 0; // 0 and 1 are not prime numbers
    // for (int i = 2; i * i <= N; i++)
    // {
    //     if (isPrime[i])
    //     {
    //         for (int j = i * i; j < N; j += i)
    //         {
    //             isPrime[j] = false;
    //         }
    //     }
    // }

    // for (int i = 2; i < N; i++)
    // {
    //     if (isPrime[i])
    //     {
    //         cout << i << " \n";
    //     }
    // }

    //--------->>>>>>>> Highest and Lowest Prime Factors of a number
    // isPrime[0] = isPrime[1] = 0;
    // for (int i = 2; i * i <= N; i++)
    // {
    //     if (isPrime[i])
    //     {
    //         hp[i] = lp[i] = i;
    //         for (int j = 2 * i; j < N; j += i)
    //         {
    //             isPrime[j] = false;
    //             hp[j] = i;
    //             if (lp[j] == 0)
    //             {
    //                 lp[j] = i;
    //             }
    //         }
    //     }
    // }

    // for (int i = 2; i < N; i++)
    // {
    //     cout << i << " " << hp[i] << " " << lp[i] << " \n"; // Print highest and lowest prime factors
    // }

    // ------------------->>>>>>>>>> Prime Factorization
    // isPrime[0] = isPrime[1] = 0;
    // for (int i = 2; i < N; i++)
    // {
    //     if (isPrime[i])
    //     {
    //         hp[i] = lp[i] = i;
    //         for (int j = i * i; j < N; j += i)
    //         {
    //             isPrime[j] = false;
    //             hp[j] = i;
    //             if (lp[j] == 0)
    //             {
    //                 lp[j] = i;
    //             }
    //         }
    //     }
    // }

    // int num = 24;
    // // vector<int> prime_facte;
    // unordered_map<int, int> prime_facte;

    // while (num > 1)
    // {
    //     int prime_fact = hp[num];
    //     while (num % prime_fact == 0)
    //     {
    //         num /= prime_fact;
    //         prime_facte[prime_fact]++;
    //     }
    // }
    // for (auto &&it : prime_facte)
    // {
    //     // cout << it << "\n";
    //     cout << it.first << " " << it.second << "\n";
    // }

    // ----------->>>>>>>>>  Listing All Divisors
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = i; j < N; j += i)
        {
            divisiors[j].push_back(i);
        }
    }

    for (int i = 2; i < N; i++)
    {
        for (auto &&it : divisiors[i])
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
