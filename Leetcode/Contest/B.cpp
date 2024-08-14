#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution
{
    vector<int> sieve(int max)
    {
        vector<bool> isPrime(max + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= max; ++i)
        {
            if (isPrime[i])
            {
                for (int j = i * i; j <= max; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for (int i = 2; i <= max; ++i)
        {
            if (isPrime[i])
            {
                primes.push_back(i);
            }
        }
        return primes;
    }

public:
    int nonSpecialCount(int l, int r)
    {
        int maxPrime = sqrt(r);
        vector<int> primes = sieve(maxPrime);

        vector<int> specialNumbers;
        for (int prime : primes)
        {
            int specialNumber = prime * prime;
            if (specialNumber >= l && specialNumber <= r)
            {
                specialNumbers.push_back(specialNumber);
            }
        }

        int totalNumbers = r - l + 1;
        int specialCount = specialNumbers.size();
        int nonSpecialCount = totalNumbers - specialCount;

        return nonSpecialCount;
    }
};

int main()
{
    Solution sol;

    int result = sol.nonSpecialCount(4, 16);
    cout << result << endl;

    return 0;
}
