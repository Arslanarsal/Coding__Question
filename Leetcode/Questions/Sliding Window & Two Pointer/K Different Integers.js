/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */

function solve(nums, k) {
    let l = 0;
    let r = 0;
    let ans = 0;
    let count = 0;
    let mp = new Map();
    let n = nums.length;
    for (let i = 0; i < n; i++) {
        let value = nums[i];
        if (mp.has(value)) {
            mp.set(value, mp.get(value) + 1);
        } else {
            mp.set(value, 1);
            count++;
        }

        while (count > k) {
            if (mp.get(nums[l]) === 1) {
                mp.delete(nums[l]);
                count--;
            } else {
                mp.set(nums[l], mp.get(nums[l]) - 1);
            }
            l++;
        }
        ans = ans + (i - l + 1);
    }
    return ans;
}


var subarraysWithKDistinct = function (nums, k) {
    return solve(nums , k ) - solve(nums , k-1);
};