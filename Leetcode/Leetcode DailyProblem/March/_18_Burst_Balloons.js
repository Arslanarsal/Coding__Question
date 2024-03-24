// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     int findMinArrowShots(vector<vector<int>> &points)
//     {
//         sort(points.begin(), points.end());
//         int ans = 0;
//         int n = points.size();
//         for (int i = 0; i < n; i++)
//         {
//             int last = points[i][1];
//             while (i < n && points[i][0] <= last)
//             {
//                 last = min(last, points[i][1]);
//                 i++;
//             }
//             i--;
//             ans++;
//         }
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

/**
 * @param {number[][]} points
 * @return {number}
 */
var findMinArrowShots = function (points) {
    points.sort(function (a, b) { return a[0] - b[0] });
    let ans = 0;
    let n = points.length;
    for (let i = 0; i < n; i++) {
        let last = points[i][1];
        while (i < n && points[i][0] <= last) {
            last = Math.min(last, points[i][1]);
            i++;
        }
        i--;
        ans++;
    }
    return ans;
};