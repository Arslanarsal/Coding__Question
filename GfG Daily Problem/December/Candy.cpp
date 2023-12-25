#include <bits/stdc++.h>
using namespace std;

// Function to find minimum number of candies.
int minCandy(int N, vector<int> &ratings)
{
    // Creating a vector with size N and initializing all elements to 1.
    vector<int> c(N, 1);

    // Iterating over the ratings array starting from index 1.
    for (int i = 1; i < N; i++)
        // If the current rating is greater than the previous rating,
        // increment the current candy count by 1.
        if (ratings[i] > ratings[i - 1])
            c[i] = c[i - 1] + 1;

    // Iterating over the ratings array backwards starting from the second last index.
    for (int i = N - 2; i >= 0; i--)
        // If the current rating is greater than the next rating,
        // update the current candy count to the maximum of its current value and the next candy count plus 1.
        if (ratings[i] > ratings[i + 1])
            c[i] = max(c[i], c[i + 1] + 1);

    // Initializing a variable res to store the total number of candies.
    int res = 0;

    // Iterating over the candies vector and adding each candy count to res.
    for (auto t : c)
        res += t;

    // Returning the total number of candies.
    return res;
}

int main()
{

    return 0;
}