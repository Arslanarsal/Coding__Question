// #include <bits/stdc++.h>
// using namespace std;

// // class Solution
// // {
// //     int mindiff(vector<int> &nums, int arr1, int arr2, int i, int n, int x, int y, vector<vector<vector<int>>> &dp)
// //     {
// //         if (i > nums.size() || x > n / 2 || y > n / 2)
// //         {
// //             return INT_MAX;
// //         }
// //         if (x == n / 2 && y == n / 2 && i == nums.size())
// //         {
// //             return abs(arr1 - arr2);
// //         }
// //         if (dp[i][x][y] != -1)
// //         {
// //             return dp[i][x][y];
// //         }

// //         int temp1 = mindiff(nums, arr1 + nums[i], arr2, i + 1, n, x + 1, y, dp);
// //         int temp2 = mindiff(nums, arr1, arr2 + nums[i], i + 1, n, x, y + 1, dp);
// //         return dp[i][x][y] = min(temp1, temp2);
// //     }

// // public:
// //     int minimumDifference(vector<int> &nums)
// //     {
// //         int n = nums.size();
// //         vector<vector<vector<int>>> dp(n, vector<vector<int>>(n / 2 + 1, vector<int>(n / 2 + 1, -1)));
// //         return mindiff(nums, 0, 0, 0, n, 0, 0, dp);
// //     }
// // };

// int minSubsetSumDifference(vector<int> &arr, int n)
// {
//     int sum = 0;
//     for (int i = 0; i < n; i++)
//     {
//         sum += arr[i];
//     }

//     vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));
//     for (int i = 0; i < n; i++)
//     {
//         dp[i][0] = true;
//     }
//     dp[0][arr[0]] = true;

//     for (int i = 1; i < n; i++)
//     {
//         for (int j = 1; j <= sum; j++)
//         {
//             bool nottake = dp[i - 1][j];
//             bool take = false;
//             if (j >= arr[i])
//             {
//                 take = dp[i - 1][j - arr[i]];
//             }
//             dp[i][j] = (take | nottake);
//         }
//     }

//     int mini = 1e9;
//     for (int i = 0; i <= sum / 2; i++)
//     {
//         if (dp[n - 1][i])
//         {
//             mini = min(mini, abs((sum - i) - i));
//         }
//     }
//     return mini;
// }

// int main()
// {

//     return 0;
// }

/**
 * @param {number[]} nums
 * @return {number}
 */

function solve(nums, index, sum1, sum2, count1, count2, n, dp) {
    if (index === n) {
      return Math.abs(sum1 - sum2);
    }
    
    if (dp[index][count1][count2] !== -1) {
      return dp[index][count1][count2];
    }
    
    let left = Number.MAX_SAFE_INTEGER;
    let right = Number.MAX_SAFE_INTEGER;
    
    if (count1 < n / 2) {
      left = solve(nums, index + 1, sum1 + nums[index], sum2, count1 + 1, count2, n, dp);
    }
    
    if (count2 < n / 2) {
      right = solve(nums, index + 1, sum1, sum2 + nums[index], count1, count2 + 1, n, dp);
    }
    
    dp[index][count1][count2] = Math.min(left, right);
    return dp[index][count1][count2];
  }
  
  var minimumDifference = function (nums) {
    let n = nums.length;
    let dp = Array.from({ length: n }, () =>
      Array.from({ length: Math.floor(n / 2) + 1 }, () =>
        Array(Math.floor(n / 2) + 1).fill(-1)
      )
    );
    return solve(nums, 0, 0, 0, 0, 0, n, dp);
  };
  
