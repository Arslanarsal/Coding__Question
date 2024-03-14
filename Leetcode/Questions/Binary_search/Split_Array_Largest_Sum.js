// #include <bits/stdc++.h>
// using namespace std;

// class Solution
// {

//     int find(vector<int> &nums, int mid, int k, int &temp)
//     {
//         int parti = 0;
//         long long maxsum = 0;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             if (maxsum + nums[i] <= mid)
//             {
//                 maxsum += nums[i];
//             }
//             else
//             {
//                 parti++;
//                 temp = max(temp, (int)maxsum);
//                 maxsum = nums[i];
//             }
//         }
//         return parti;
//     }

// public:
//     int splitArray(vector<int> &nums, int k)
//     {
//         int low = *max_element(nums.begin(), nums.end());
//         int high = accumulate(nums.begin(), nums.end(), 0);
//         int ans = 0;
//         int temp = 0;
//         while (low <= high)
//         {
//             temp = 0;
//             int mid = (low + high) / 2;
//             int x = find(nums, mid, k, temp);
//             if (x >= k)
//             {
//                 ans = max(ans, temp);
//                 low = mid + 1;
//             }
//             else
//             {
//                 high = mid - 1;
//             }
//         }
//         return low;
//     }
// };

// int main()
// {
//     vector<int> v = {1, 4, 4};

//     Solution sol;
//     cout << sol.splitArray(v, 3);
//     return 0;
// }

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
function Findee(nums, obj, mid) {
    let ret = 0;
    let presum = 0;
    for (let i = 0; i < nums.length; i++) {
        if (presum + nums[i] <= mid) {
            presum += nums[i];

        } else {
            ret++;
            obj = Math.max(obj, presum);
            presum = nums[i];
        }
    }
    return ret;
}

function find(nums, mid, temp) {
    let parti = 0;
    let maxsum = 0;
    for (let i = 0; i < nums.length; i++) {
        if (maxsum + nums[i] <= mid) {
            maxsum += nums[i];
        } else {
            parti++;
            temp = Math.max(temp, maxsum);
            maxsum = nums[i];
        }
    }
    return parti;
}

var splitArray = function (nums, k) {
    let low = Math.max(...nums);
    let high = nums.reduce((acc, init) => acc + init, 0);
    let ans = 0;

    let value = 0

    while (low <= high) {
        value = 0;
        let mid = Math.floor((high + low) / 2);

        let flag = find(nums, value, mid);

        if (flag >= k) {
            console.log(mid, value, ans);
            ans = Math.max(ans, value);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
};

// let arr = [7, 2, 5, 10, 8];
// console.log(splitArray(arr, 2));



// function find(nums, mid, k, temp) {
//     let parti = 0;
//     let maxsum = 0;
//     for (let i = 0; i < nums.length; i++) {
//         if (maxsum + nums[i] <= mid) {
//             maxsum += nums[i];
//         } else {
//             parti++;
//             temp = Math.max(temp, maxsum);
//             maxsum = nums[i];
//         }
//     }
//     return parti;
// }


var splitArray = function(nums, k) {
    let low = Math.max(...nums);
    let high = nums.reduce((acc, curr) => acc + curr, 0);
    let ans = 0;
    let temp = 0;
    while (low <= high) {
        temp = 0;
        let mid = Math.floor((low + high) / 2);
        let x = find(nums, mid, k, temp);
        if (x >= k) {
            ans = Math.max(ans, temp);
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
};


