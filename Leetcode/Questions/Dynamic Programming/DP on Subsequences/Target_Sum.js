/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */

function solve(i, nums, target) {
  if (i == 0) {
    if (target + nums[i] == 0 && target - nums[i] == 0) {
      return 2;
    } else if (target + nums[i] == 0 || target - nums[i] == 0) {
      return 1;
    }
    return 0;
  }
  return (
    solve(i - 1, nums, target - nums[i]) + solve(i, nums, target + nums[i])
  );
}
var findTargetSumWays = function (nums, target) {
  let n = nums.length;
  return solve(n - 1, nums, target);
};
