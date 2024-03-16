/**
 * @param {number[]} nums
 * @return {number}
 */
function f(nums) {
  let ans = 0;
  let count = 0;
  let mp = new Map();
  let n = nums.length;
  mp.set(0, -1);
  for (let i = 0; i < n; i++) {
    nums[i] == 1 ? count++ : count--;
    if (mp.has(count)) {
      console.log(mp.get(count));
      ans = Math.max(ans, i - mp.get(count));
    } else {
      mp.set(count, i);
    }
  }
  return ans;
}

let nums = [0, 1, 0];
f(nums);
