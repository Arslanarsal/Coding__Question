/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var f = function (nums, k) {
  let n = nums.length;
  let ans = 0;
  let map = new Map();
  let count = 0;
  let i = 0;
  for (let j = 0; j < n; j++) {
    let valueCheck = nums[j];

    if (map.has(valueCheck)) {
      map.set(valueCheck, map.get(valueCheck) + 1);
    } else {
      map.set(valueCheck, 1);
      count++;
    }

    while (count > k) {
      if (map.get(nums[i]) == 1) {
        map.delete(nums[i]);
        count--;
      } else {
        map.set(nums[i], map.get(nums[i]) - 1);
      }
      i++;
    }

    ans = ans + (j - i + 1);
  }
  return ans;
};

var subarraysWithKDistinct = function (nums, k) {
  return f(nums, k) - f(nums, k - 1);
};
