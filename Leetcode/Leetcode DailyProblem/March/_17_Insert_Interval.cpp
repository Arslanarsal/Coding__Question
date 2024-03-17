#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> merged;
        int i = 0;

        while (i < intervals.size() && intervals[i][1] < newInterval[0])
        {
            merged.push_back(intervals[i]);
            i++;
        }

        while (i < intervals.size() && intervals[i][0] <= newInterval[1])
        {
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i++;
        }
        merged.push_back(newInterval);

        while (i < intervals.size())
        {
            merged.push_back(intervals[i]);
            i++;
        }

        return merged;
    }
};

int main()
{

    return 0;
}
// if (a[0][0] < b[0][0])
// {
//     ans.push(a[0]);
//     i++;
// }
// else
// {
//     ans.push(b[0]);
//     j++;
// }
// console.log(ans[0]);
// while (i < n && j < m)
// {
//     let k = ans.length - 1;
//     if (ans[k][1] >= a[i][0])
//     {
//             ans[k][0] = Math.min(ans[k][0], a[i][0]);
//             ans[k][1] = Math.max(ans[k][1], a[i][1]);
//             i++;
//         }
//         else if (ans[k][1] >= b[i][0])
//         {
//             ans[k][0] = Math.min(ans[k][0], b[i][0]);
//             ans[k][1] = Math.max(ans[k][1], b[i][1]);
//             j++;
//         }
//         else
//         {
//             if (a[0][0] < b[0][0])
//             {
//                 ans.push(a[0]);
//                 i++;
//             }
//             else
//             {
//                 ans.push(b[0]);
//                 j++;
//             }
//         }
//     }

//     while (i < n)
//     {
//         let k = ans.length - 1;
//         if (ans[k][1] >= a[i][0])
//         {
//             ans[k][0] = Math.min(ans[k][0], a[i][0]);
//             ans[k][1] = Math.max(ans[k][1], a[i][1]);
//         }
//         else
//         {
//             ans.push(a[0]);
//         }
//         i++;
//     }

//     while (j < m)
//     {
//         let k = ans.length - 1;
//         if (ans[k][1] >= b[i][0])
//         {
//             ans[k][0] = Math.min(ans[k][0], b[i][0]);
//             ans[k][1] = Math.max(ans[k][1], b[i][1]);
//         }
//         else
//         {
//             ans.push(b[0]);
//         }
//         j++;
//     }
//     return ans;
// };

// let a = [
//     [ 1, 3 ],
//     [ 6, 9 ],
// ];
// let b = [ 2, 5 ];

// // console.log(insert(a, b));
// insert(a, b);

// /**
//  * @param {number[][]} intervals
//  * @param {number[]} newInterval
//  * @return {number[][]}
//  */
// var insert = function (a, b) {
//   let ans = [];

//   let i = 0,
//     j = 0,
//     n = a.length,
//     m = b.length;

//   if (a[0][0] < b[0][0]) {
//     ans.push(a[0]);
//     i++;
//   } else {
//     ans.push(b[0]);
//     j++;
//   }
//   console.log(ans[0]);
//   while (i < n && j < m) {
//     let k = ans.length - 1;
//     if (ans[k][1] >= a[i][0]) {
//       ans[k][0] = Math.min(ans[k][0], a[i][0]);
//       ans[k][1] = Math.max(ans[k][1], a[i][1]);
//       i++;
//     } else if (ans[k][1] >= b[i][0]) {
//       ans[k][0] = Math.min(ans[k][0], b[i][0]);
//       ans[k][1] = Math.max(ans[k][1], b[i][1]);
//       j++;
//     } else {
//       if (a[0][0] < b[0][0]) {
//         ans.push(a[0]);
//         i++;
//       } else {
//         ans.push(b[0]);
//         j++;
//       }
//     }
//   }

//   while (i < n) {
//     let k = ans.length - 1;
//     if (ans[k][1] >= a[i][0]) {
//       ans[k][0] = Math.min(ans[k][0], a[i][0]);
//       ans[k][1] = Math.max(ans[k][1], a[i][1]);
//     } else {
//       ans.push(a[0]);
//     }
//     i++;
//   }

//   while (j < m) {
//     let k = ans.length - 1;
//     if (ans[k][1] >= b[i][0]) {
//       ans[k][0] = Math.min(ans[k][0], b[i][0]);
//       ans[k][1] = Math.max(ans[k][1], b[i][1]);
//     } else {
//       ans.push(b[0]);
//     }
//     j++;
//   }
//   return ans;
// };

// let a = [
//   [1, 3],
//   [6, 9],
// ];
// let b = [2, 5];

// // console.log(insert(a, b));
// insert(a, b);
