/**
 * @param {string} s
 * @param {string} t
 * @param {number} maxCost
 * @return {number}
 */
var equalSubstring = function (s, t, maxCost) {
  let n = s.length;
  let cost = 0;
  let i = 0;
  let j = 0;
  let ans = 0;
  while (i < n) {
    cost += Math.abs(s.charCodeAt(i) - t.charCodeAt(i));

    while (cost > maxCost && j <= i) {
      cost -= Math.abs(s.charCodeAt(j) - t.charCodeAt(j));
      j++;
    }
    ans = Math.max(ans, i - j + 1);
    i++;
  }
  return ans;
};
equalSubstring("abcd", "bcdf", 3);
