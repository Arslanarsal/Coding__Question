#include <bits/stdc++.h>
using namespace std;

/*
    Time Complexity : O(2 ^ N)
    Space Complexity : O(N)
    
    Where ‘N’ is the number of elements in the array/list.
*/

int maxNonAdjacentSumHelper(vector<int> &nums, int index){
    // Base Case.
    if (index < 0){
        return 0;
    }

    // Including the current element of the given array/list in our subsequence.
    int optionA = maxNonAdjacentSumHelper(nums, index - 2) + nums[index];

    // Excluding the current element of the given array/list from our subsequence.
    int optionB = maxNonAdjacentSumHelper(nums, index - 1);

    return max(optionA, optionB);
}

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();
//     return maxNonAdjacentSumHelper(nums, n - 1);
// }

/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    Where 'N' is the number of elements in the array/list.
*/

// int maximumNonAdjacentSum(vector<int> &nums){
//     int n = nums.size();

//     if (n == 0){
//         return 0;
//     }

//     // Array to store previous results.
//     vector<int> dp(n + 1);

//     // Base Cases.
//     dp[0] = 0;
//     dp[1] = nums[0];

//     for (int i = 2; i <= n; i++){
//         int optionA = dp[i - 2] + nums[i - 1];
//         int optionB = dp[i - 1];
//         dp[i] = max(optionA, optionB);
//     }
//     return dp[n];
// }


/*
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where ‘N’ is the number of elements in the array/list.
*/

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();

    // Two variables to store the previous results.
    int prevFirst = 0;
    int prevSecond = 0;

    for (int i = 0; i < n; i++){
        int temp = prevFirst;
        prevFirst = max(prevSecond + nums[i], prevFirst);
        prevSecond = temp;
    }
    return prevFirst;
}
int main()
{
    vector<int> v = {2, 1, 4, 9};
    cout << maximumNonAdjacentSum(v);

    return 0;
}