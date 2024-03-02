/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  if (x < 0) return false; // Negative numbers are not palindromes
  let num1 = x;
  let num2 = 0;
  while (x !== 0) {
    num2 = num2 * 10 + (x % 10);
    x = Math.floor(x / 10);
  }
  return num1 === num2;
};
