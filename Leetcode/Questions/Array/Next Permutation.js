/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var nextPermutation = function (nums) {
    let n = nums.length;
    let i = n - 1;
    while (i > 0) {
        if (nums[i - 1] < nums[i]) {
            break;
        }
        i--;
    }
    if (nums[i - 1] < nums[i]) {
        let a = nums[i];
        nums[i] = nums[i - 1];
        nums[i - 1] = a;
    } else {
        nums.reverse();
    }
    return nums;
};