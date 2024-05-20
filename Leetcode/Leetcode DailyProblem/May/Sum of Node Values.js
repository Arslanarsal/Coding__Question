/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number[][]} edges
 * @return {number}
 */
var maximumValueSum = function (nums, k, edges) {
  let ans = 0;
  let n = nums.length;
  let count = 0;
  let minus = Number.MAX_SAFE_INTEGER;
  for (let i = 0; i < n; i++) {
    if ((nums[i] ^ k) > nums[i]) {
      count++;
      ans += nums[i] ^ k;
    } else {
      ans += nums[i];
    }
    minus = Math.min(minus, Math.abs(nums[i] - (nums[i] ^ k)));
  }
  return count & 1 ? ans - minus : ans;
};
