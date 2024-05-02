// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {
// public:
//     vector<int> maxSlidingWindow(vector<int> &nums, int k)
//     {
//         vector<int> ans;
//         deque<int> dq;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (!dq.empty() && dq.front() == i - k)
//             {
//                 dq.pop_front();
//             }
//             while (!dq.empty() && nums[dq.back()] < nums[i])
//             {
//                 dq.pop_back();
//             }
//             dq.push_back(i);

//             if (i >= k - 1)
//             {
//                 ans.push_back(nums[dq.front()]);
//             }
//         }
//         return ans;
//     }
// };

// int main()
// {

//     return 0;
// }

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
var maxSlidingWindow = function (nums, k) {

    let n = nums.length;
    let ans = [];
    let q = [];
    for (let i = 0; i < n; i++) {

        if (q.length && q[0] == i - k) {
            q.shift();
        }
        while (q.length && nums[q[q.length - 1]] < nums[i]) {
            q.pop();
        }
        q.push(i);
        if (i >= k - 1) {
            ans.push(nums[q[0]]);
        }
    }
    return ans;
};