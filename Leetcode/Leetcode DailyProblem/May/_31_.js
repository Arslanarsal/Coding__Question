/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumber = function (nums) {
  let num = 0;
  for (const i of nums) {
    num ^= i;
  }
  let k = 0;
  for (let i = 0; i < 31; i++) {
    if (num & (1 << i)) {
      k = k | (1 << i);
      break;
    }
  }
  let num1 = 0,
    num2 = 0;
  for (const i of nums) {
    if (k & i) {
      num1 ^= i;
    } else {
      num2 ^= i;
    }
  }
  return { num1, num2 };
};
