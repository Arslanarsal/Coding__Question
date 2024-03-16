/**
 * @param {number[]} nums
 * @return {number[]}
 */
/**
 * @param {number[]} nums
 * @return {number[]}
 */

function f(nums) {
  let length = nums.length;
  let output = [1];
  let rightSide = 1;

  for (let i = 1; i < nums.length; i++) {
    output[i] = output[i - 1] * nums[i - 1];
  }

  for (let i = length - 1; i >= 0; i--) {
    output[i] *= rightSide;
    rightSide *= nums[i];
  }

  return output;
}

let nums = [1, 2, 3, 4];
console.log(f(nums));
