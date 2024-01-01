#include <bits/stdc++.h>
using namespace std;

// Recursive solution with memoization using dp array
int f(vector<int> &heights, int idx, vector<int> &dp)
{
    // Base case: if at the start, no cost
    if (idx == 0)
    {
        return 0;
    }
    // If the value is already calculated, return it
    if (dp[idx] != -1)
    {
        return dp[idx];
    }
    // Calculate cost for jumping to the left and right positions
    int left = f(heights, idx - 1, dp) + abs(heights[idx] - heights[idx - 1]);
    int right = INT_MAX;
    if (idx > 1)
    {
        right = f(heights, idx - 2, dp) + abs(heights[idx] - heights[idx - 2]);
    }
    // Store the minimum cost in dp array and return it
    return dp[idx] = min(left, right);
}

// Function to initiate the recursive solution
int frogJump(int n, vector<int> &heights)
{
    // If there are fewer than or equal to 2 elements, no cost
    if (n <= 2)
    {
        return 0;
    }
    // Initialize dp array with -1 to indicate uncalculated values
    vector<int> dp(n + 1, -1);
    // Start recursion from index n - 1 (0-indexed)
    return f(heights, n - 1, dp);
}

// Dynamic programming solution using bottom-up approach and dp array
int frogJump(int n, vector<int> &heights)
{
    // Create a dp array to store the minimum cost at each index
    vector<int> dp(n, 0);
    dp[0] = 0; // Base case: cost to reach the first position is 0
    for (int i = 1; i < n; i++)
    {
        // Calculate cost for jumping to the left and right positions
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }
        // Store the minimum cost at index i
        dp[i] = min(left, right);
    }
    // Return the minimum cost to reach the last position
    return dp[n - 1];
}

// Optimized dynamic programming solution using constant space
int frogJump(int n, vector<int> &heights)
{
    // Initialize variables to track the cost at previous positions
    int pre = 0; // Cost to reach the first position is 0
    int pre2 = 0;
    for (int i = 1; i < n; i++)
    {
        // Calculate cost for jumping to the left and right positions
        int left = pre + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1)
        {
            right = pre2 + abs(heights[i] - heights[i - 2]);
        }
        // Store the minimum cost at the current position
        int cur = min(left, right);
        // Update previous position costs
        pre2 = pre;
        pre = cur;
    }
    // Return the minimum cost to reach the last position
    return pre;
}

int main()
{
    vector<int> v = {10, 20, 30, 10};
    // Call the frogJump function and print the result
    cout << frogJump(3, v);
    return 0;
}
